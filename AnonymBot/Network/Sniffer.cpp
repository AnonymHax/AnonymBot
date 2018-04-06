#include "Sniffer.h"

Sniffer::Sniffer():
    m_client(NULL),
    m_hostAddress(MAIN_SERVER_IP_1),
    m_expectedClientDisconnection(false),
    m_expectedServerDisconnection(false)
{
    m_listener.listen(QHostAddress::Any, 5555);
    connect(&m_listener, SIGNAL(newConnection()), this, SLOT(getClient()));
    qDebug()<<"Server is listening";

    connect(&m_server, SIGNAL(disconnected()), this, SLOT(serverDisconnection()));
    connect(&m_server, SIGNAL(readyRead()), this, SLOT(processServerData()));
}

void Sniffer::reset()
{
    m_hostAddress = MAIN_SERVER_IP_1;

    if(m_client != NULL)
    {
        m_client->disconnectFromHost();
        m_client->deleteLater();
        m_client = NULL;
    }

    m_server.disconnectFromHost();

    m_serverBuffer.reset();
    m_clientBuffer.reset();
}

void Sniffer::clientDisconnection()
{
    if(m_expectedClientDisconnection)
    {
        m_expectedClientDisconnection = false;
        qDebug()<<"Client disconnected as expected";
    }

    else
    {
        qDebug()<<"Client disconnected";
        reset();
    }
}

void Sniffer::serverDisconnection()
{
    if(m_expectedServerDisconnection)
    {
        m_expectedServerDisconnection = false;
        qDebug()<<"Server disconnected as expected";
    }

    else
    {
        qDebug()<<"Server disconnected";
        reset();
    }
}

void Sniffer::getClient()
{
    qDebug()<<"Client connected";

    m_client = m_listener.nextPendingConnection();
    qDebug()<< m_client->peerAddress();
    m_server.disconnectFromHost();

    m_server.connectToHost(m_hostAddress, MAIN_SERVER_PORT_1);
    connect(m_client, SIGNAL(readyRead()), this, SLOT(processClientData()));
    connect(m_client, SIGNAL(disconnected()), this, SLOT(clientDisconnection()));
}

void Sniffer::processClientData()
{
    qDebug()<<"\nCLIENT START";
    QList<MessageInfos> messages = m_clientBuffer.readPacket(m_client->readAll());
    qDebug()<<"CLIENT END\n";

    qDebug()<<"\nCLIENT RETRANSMISSION";

    foreach(MessageInfos messageInfos, messages)
    {
        bool hasModifiedMessage = false;
        Reader reader(messageInfos.messageData);

        switch(messageInfos.messageType)
        {
        default:
            break;

        case MessageEnum::GAMEROLEPLAYATTACKMONSTERREQUESTMESSAGE:
        {
            GameRolePlayAttackMonsterRequestMessage message;
            message.deserialize(&reader);

            qDebug()<<"MONSTER ATTACK"<<message.monsterGroupId;
        }
            break;

        case MessageEnum::BASICLATENCYSTATSMESSAGE:
        {
            BasicLatencyStatsMessage message;
            message.deserialize(&reader);

            static int hasPassed = 0;

            hasPassed++;

            qDebug()<<"N°"<<hasPassed<<" LATENCY"<<message.latency<<"SAMPLECOUNT"<<message.sampleCount<<"MAX"<<message.max;

            if(hasPassed >= 2)
            {
                message.latency += -1*hasPassed;
                qDebug()<<"Latency modified :"<<message.latency;
                hasModifiedMessage = true;
                m_server.write(m_clientBuffer.writePacket(message).getBuffer());
            }
        }
            break;
        }

        if(!hasModifiedMessage)
            m_server.write(m_clientBuffer.writePacket(messageInfos).getBuffer());
    }

    qDebug()<<"CLIENT RETRANSMISSION END\n";
}

void Sniffer::processServerData()
{
    qDebug()<<"\nSERVER START";
    QList<MessageInfos> messages = m_serverBuffer.readPacket(m_server.readAll());
    qDebug()<<"SERVER END\n";

    qDebug()<<"\nSERVER RETRANSMISSION";

    foreach(MessageInfos messageInfos, messages)
    {
        bool hasModifiedMessage = false;
        Reader reader(messageInfos.messageData);

        switch(messageInfos.messageType)
        {
        default:
            break;

        case MessageEnum::CHARACTERSELECTEDSUCCESSMESSAGE:
        {
            CharacterSelectedSuccessMessage message;
            message.deserialize(&reader);
            qDebug()<<"PlayerId"<<message.infos->id;
        }
            break;


        case MessageEnum::SELECTEDSERVERDATAEXTENDEDMESSAGE:
        case MessageEnum::SELECTEDSERVERDATAMESSAGE:
        {
            SelectedServerDataMessage message;
            message.deserialize(&reader);
            m_hostAddress = message.address;
            message.address = "127.0.0.1";

            qDebug()<<"Next Server"<<m_hostAddress;
            qDebug()<<"Ticket"<<message.ticket;
            hasModifiedMessage = true;

            hasModifiedMessage = true;
            m_client->write(m_clientBuffer.writePacket(message).getBuffer());

            m_expectedServerDisconnection = true;
            m_expectedClientDisconnection = true;
            m_client->disconnectFromHost();
        }
            break;
        }

        if(!hasModifiedMessage)
            m_client->write(m_clientBuffer.writePacket(messageInfos).getBuffer());
    }

    qDebug()<<"SERVER RETRANSMISSION END\n";
}
