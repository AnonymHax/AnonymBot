#include "SecureServer.h"

SecureServer::SecureServer(QObject *parent) :
    QTcpServer(parent)
{
}

void SecureServer::incomingConnection(qintptr handle)
{
    QSslSocket* socket = new QSslSocket(this);
    socket->setProtocol(QSsl::SslV3);

    socket->setPrivateKey(":/Resources/server.key");
    socket->setLocalCertificate(":/Resources/server.crt");

    if (socket->setSocketDescriptor(handle))
    {
        m_pendingConnections.enqueue(socket);
        socket->startServerEncryption();
    }

    else
        delete socket;
}

QTcpSocket* SecureServer::nextPendingConnection()
{
    if (m_pendingConnections.isEmpty())
        return NULL;

    else
        return m_pendingConnections.dequeue();
}
