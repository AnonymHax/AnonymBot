#ifndef SECURESERVER_H
#define SECURESERVER_H

#include "Public.h"

class SecureServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit SecureServer(QObject *parent = 0);

    virtual void incomingConnection(qintptr handle);
    virtual QTcpSocket* nextPendingConnection();

private:
    QQueue<QSslSocket*> m_pendingConnections;
};

#endif // SECURESERVER_H
