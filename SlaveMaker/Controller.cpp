#include "Controller.h"

bool operator==(const ConnectedAccount &left, const ConnectedAccount &right)
{
    if(left.login == right.login)
        return true;

    return false;
}

Controller::Controller():
    m_isProcessing(false),
    m_totalNbActiveBots(0)
{
    m_dataBase = QSqlDatabase::addDatabase("QMYSQL");
    m_dataBase.setHostName("XXX.XXX.XXX.X");
    m_dataBase.setUserName("XXXX");
    m_dataBase.setPassword("XXXX");
    m_dataBase.setDatabaseName("web");

    connect(&m_dofusServer, SIGNAL(dataReceived(QList<DofusMessageInfos>)), this, SLOT(processDofusData(QList<DofusMessageInfos>)));
    connect(&m_dofusServer, SIGNAL(serverDisconnected()), this, SLOT(reset()));

    m_botServer.listen(QHostAddress::Any, SERVER_PORT);

    connect(&m_botServer, SIGNAL(newConnection()), this, SLOT(addConnection()));

    m_timer.start(120000);

    connect(&m_timer, SIGNAL(timeout()), this, SLOT(updateStats()));
}

 Controller::~Controller()
 {

 }

void Controller::addConnection()
{
    QSslSocket *socket = static_cast<QSslSocket*>(m_botServer.nextPendingConnection());

    if(socket != NULL)
    {
        connect(socket, SIGNAL(disconnected()), this, SLOT(removeConnection()));

        //if(m_dofusServer.isConnected())
        if(1)
        {
            connect(socket, SIGNAL(readyRead()), this, SLOT(processBotData()));
            connect(socket, SIGNAL(encrypted()), this, SLOT(connectionEncryptionSuccess()));
            connect(socket, SIGNAL(sslErrors(QList<QSslError>)), this, SLOT(connectionEncryptionFailure(QList<QSslError>)));
            connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(connectionError()));
            m_connectedAccounts.insert(socket, ConnectedAccount());
            qDebug()<<"Controller - Connection from a client added, there is now"<<m_connectedAccounts.size()<<"client(s) connected";
        }

        else
        {
            qDebug()<<"Controller - Connection from a client refused, because not connected to dofus";
            socket->disconnectFromHost();
        }
    }
}

void Controller::connectionEncryptionSuccess()
{
    QSslSocket *socket = static_cast<QSslSocket*>(QObject::sender());
    ServerUpdateMessage answer;
    answer.nbActiveBots = m_totalNbActiveBots;
    socket->write(m_connectedAccounts[socket].buffer.writePacket(answer).getBuffer());
    qDebug()<<"Controller - Connection with a client secured";
}

void Controller::connectionEncryptionFailure(QList<QSslError> errors)
{
    QSslSocket *socket = static_cast<QSslSocket*>(QObject::sender());
    socket->disconnectFromHost();
    qDebug()<<"Controller - ERROR - Connection with a client not secured"<<errors;
}

void Controller::connectionError()
{
    QSslSocket *socket = static_cast<QSslSocket*>(QObject::sender());
    qDebug()<<"Controller - ERROR - Socket encountered an error"<<socket->errorString();
}

void Controller::removeConnection()
{
    QSslSocket *socket = static_cast<QSslSocket*>(QObject::sender());

    if(m_connectedAccounts.contains(socket))
    {
        qDebug()<<"Controller - Connection from a client ("<<m_connectedAccounts[socket].login<<") is now terminated, there is now"<<m_connectedAccounts.size()-1<<"bot(s) still connected";
        m_connectedAccounts.remove(socket);
    }

    socket->deleteLater();
}

void Controller::processBotData()
{
    QSslSocket *socket = static_cast<QSslSocket*>(QObject::sender());

    qDebug()<<"Controller - Data received from a client ("<<m_connectedAccounts[socket].login<<") - Bytes :"<<socket->bytesAvailable();

    QList<ServerMessageInfos> messages = m_connectedAccounts[socket].buffer.readPacket(socket->readAll());

    foreach(const ServerMessageInfos &infos, messages)
    {
        Reader reader(infos.messageData);

        if(infos.messageType == ServerMessageEnum::CONNECTIONREQUESTMESSAGE || !m_connectedAccounts[socket].login.isEmpty())
        {
            switch(infos.messageType)
            {
            default:
            {
                qDebug()<<"Controller - ERROR - Unknown message type received from a client ("<<m_connectedAccounts[socket].login<<") "<<(int)infos.messageType;

                RawResolveFailureMessage answer;
                answer.reason = FailureReasonsEnum::UNKNOWN;

                socket->write(m_connectedAccounts[socket].buffer.writePacket(answer).getBuffer());
                socket->disconnectFromHost();
            }
                break;

            case ServerMessageEnum::CONNECTIONREQUESTMESSAGE:
            {
                ConnectionRequestMessage message;
                message.deserialize(&reader);

                //if(m_dataBase.open())
                if(0)
                {
                    QSqlQuery query;
                    if(query.exec("SELECT * FROM `botLogin` WHERE botLogin.UserName = '"+message.login+"'"))
                    {
                        if(!query.next())
                        {
                            qDebug()<<"Controller - The account ("<<message.login<<") doesn't exist - connection refused";
                            ConnectionFailureMessage answer;
                            answer.reason = FailureReasonsEnum::WRONGCREDENTIALS;
                            socket->write(m_connectedAccounts[socket].buffer.writePacket(answer).getBuffer());
                            socket->disconnectFromHost();
                        }

                        else
                        {
                            QString saltHash = QCryptographicHash::hash(QByteArray(query.value("Salt").toString().toLocal8Bit()), QCryptographicHash::Md5).toHex();
                            QString passwordHash = QCryptographicHash::hash(QByteArray(message.password.toLocal8Bit()), QCryptographicHash::Md5).toHex();
                            QString combinationHash = QCryptographicHash::hash(QByteArray(saltHash.toLocal8Bit()+passwordHash.toLocal8Bit()), QCryptographicHash::Md5).toHex();

                            if(combinationHash == query.value("Password").toString())
                            {
                                QHashIterator<QSslSocket*, ConnectedAccount> i(m_connectedAccounts);
                                while(i.hasNext())
                                {
                                    i.next();

                                    if(i.value().login == message.login && !message.login.isEmpty() && !message.password.isEmpty())
                                    {
                                        QSslSocket *secondSocket = i.key();
                                        ForceDisconnectionMessage answer;
                                        answer.reason = FailureReasonsEnum::MULTIPLECONNECTION;
                                        secondSocket->write(m_connectedAccounts[secondSocket].buffer.writePacket(answer).getBuffer());
                                        secondSocket->disconnectFromHost();
                                        qDebug()<<"Controller - ERROR - The account ("<<i.value().login<<") is trying to authentify, but is already connected via an other device, disconnecting the first...";
                                        break;
                                    }
                                }

                                m_connectedAccounts[socket].login = message.login;

                                qDebug()<<"Controller - The account ("<<message.login<<") has been successfully authentificated";
                                ConnectionSuccessMessage answer;
                                answer.accountType = AccountTypeEnum::PREMIUM;
                                answer.leftTime = query.value("AboTime").toLongLong();
                                socket->write(m_connectedAccounts[socket].buffer.writePacket(answer).getBuffer());
                            }

                            else
                            {
                                qDebug()<<"Controller - The password"<<message.password<<"doesn't match with the account"<<message.login<<"- connection refused";

                                ConnectionFailureMessage answer;
                                answer.reason = FailureReasonsEnum::WRONGCREDENTIALS;
                                socket->write(m_connectedAccounts[socket].buffer.writePacket(answer).getBuffer());
                                socket->disconnectFromHost();
                            }
                        }
                    }
                }

                else
                {
                    m_connectedAccounts[socket].login = message.login;

                    ConnectionSuccessMessage answer;
                    answer.accountType = AccountTypeEnum::PREMIUM;
                    answer.leftTime = 0;
                    socket->write(m_connectedAccounts[socket].buffer.writePacket(answer).getBuffer());

//                    qDebug() << "Controller - Connection with databasefailed - Reason :"<<m_dataBase.lastError();
//                    ConnectionFailureMessage answer;
//                    answer.reason = FailureReasonsEnum::UNKNOWN;
//                    socket->write(m_connectedAccounts[socket].buffer.writePacket(answer).getBuffer());
//                    socket->disconnectFromHost();
                }
            }
                break;

            case ServerMessageEnum::RAWRESOLVEREQUESTMESSAGE:
            {
                RawResolveRequestMessage message;
                message.deserialize(&reader);

                m_connectedAccounts[socket].rawRequest.indexes << message.index;

                RawDataMessage answerDofus;
                answerDofus.content = message.content;
                answerDofus.ticket = message.ticket;

                if(m_dofusServer.sendMessage(answerDofus))
                {
                    m_waitingForRaw<<socket;
                    qDebug()<<"Controller - RawDataMessage sent to dofus for an account ("<<m_connectedAccounts[socket].login<<") - Index :"<<message.index;
                }

                else
                    reset();
            }
                break;

            case ServerMessageEnum::CLIENTUPDATEMESSAGE:
            {
                ClientUpdateMessage message;
                message.deserialize(&reader);

                m_connectedAccounts[socket].nbActiveBots = message.nbActiveBots;
            }
                break;
            }
        }

        else
        {
            qDebug()<<"Controller - ERROR - Message"<<(int)infos.messageType<<"from a client that hasn't authentificated";
            ForceDisconnectionMessage answer;

            answer.reason = FailureReasonsEnum::UNKNOWN;

            socket->write(m_connectedAccounts[socket].buffer.writePacket(answer).getBuffer());
            socket->disconnectFromHost();
        }
    }
}

void Controller::processDofusData(QList<DofusMessageInfos> messages)
{
    foreach(const DofusMessageInfos &infos, messages)
    {
        switch(infos.messageType)
        {
        default:
            qDebug()<<"Controller - Unknown messageType received from dofus"<<(int)infos.messageType;
            break;

        case DofusMessageEnum::CHECKINTEGRITYMESSAGE:
        {
            if(!m_waitingForRaw.isEmpty())
            {
                QSslSocket *socket = m_waitingForRaw.first();
                m_waitingForRaw.removeFirst();

                if(m_connectedAccounts.contains(socket))
                {
                    qDebug()<<"Controller - CheckIntegrityMessage received";

                    Reader reader(infos.messageData);

                    CheckIntegrityMessage message;
                    message.deserialize(&reader);

                    qDebug()<<"Controller - Content of array"<<message.data;

                    RawResolveMessage answer;
                    answer.index = m_connectedAccounts[socket].rawRequest.indexes.first();
                    m_connectedAccounts[socket].rawRequest.indexes.removeFirst();
                    answer.data = message.data;

                    socket->write(m_connectedAccounts[socket].buffer.writePacket(answer).getBuffer());

                    qDebug()<<"Controller - SuccessMessage send to client ("<<m_connectedAccounts[socket].login<<")";
                }

                else
                    qDebug()<<"Controller - ERROR - CheckIntegrityMessage received from dofus, but client disconnected";
            }

            else
                qDebug()<<"Controller - ERROR - CheckIntegrityMessage received from dofus, but no client waiting for it";
        }
            break;
        }
    }
}

void Controller::reset()
{
    foreach(QTcpSocket *socket, m_connectedAccounts.keys())
        socket->disconnectFromHost();
}

void Controller::updateStats()
{
    QHashIterator<QSslSocket*, ConnectedAccount> i(m_connectedAccounts);

    m_totalNbActiveBots = 0;

    while(i.hasNext())
    {
        i.next();
        if(!i.value().login.isEmpty())
            m_totalNbActiveBots += i.value().nbActiveBots;
    }

    i = m_connectedAccounts;

    while(i.hasNext())
    {
        i.next();

        if(!i.value().login.isEmpty())
        {
            ServerUpdateMessage answer;
            answer.nbActiveBots = m_totalNbActiveBots;
            i.key()->write(i.value().buffer.writePacket(answer).getBuffer());
        }
    }
}
