#include "DofusServer.h"

DofusServer::DofusServer():
    m_client(NULL)
{
    m_server = new QTcpServer();
    m_server->listen(QHostAddress::Any, 8888);

    m_addresses<<"127.0.0.1"<<"87.88.128.33"<<"78.192.0.172"<<"78.250.57.159";

    connect(m_server, SIGNAL(newConnection()), this, SLOT(connectionRequested()));
}

DofusServer::~DofusServer()
{
    if(m_client)
        delete m_client;

    delete m_server;
}

bool DofusServer::sendMessage(AbstractDofusMessage &message)
{
    if(!m_client || m_client->state() == QAbstractSocket::UnconnectedState)
    {
        qDebug()<<"DofusServer - ERROR - SlaveMaker not connected to dofus, but received a request";
        return false;
    }

    else
    {
        QByteArray data = m_buffer.writePacket(message).getBuffer();
        m_client->write(data);
        return true;
    }
}

void DofusServer::connectionRequested()
{
    if(m_client == NULL)
    {
        QTcpSocket *socket = m_server->nextPendingConnection();

        if(m_addresses.contains(socket->peerAddress().toString()))
        {
            m_client = socket;
            connect(m_client, SIGNAL(readyRead()), this, SLOT(socketReadyRead()));
            connect(m_client, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));
            qDebug()<<"DofusServer - Connection with dofus established";

            m_server->pauseAccepting();
        }

        else
        {
            socket->disconnectFromHost();
            socket->deleteLater();
        }
    }
}

void DofusServer::socketReadyRead()
{
    qDebug()<<"DofusServer - Received data from dofus";

    emit dataReceived(m_buffer.readPacket(m_client->readAll()));
}

void DofusServer::socketDisconnected()
{
    qDebug()<<"DofusServer - ERROR - Connection with dofus has been interrupted"<<m_client->errorString();
    m_client->deleteLater();
    m_client = NULL;
    m_server->resumeAccepting();
    emit serverDisconnected();
}

bool DofusServer::isConnected() const
{
    if(m_client && m_client->state() == QAbstractSocket::ConnectedState)
        return true;

    return false;
}
