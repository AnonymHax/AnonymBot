#ifndef SNIFFER_H
#define SNIFFER_H

#include "Messages/MessageUtils.h"
#include "Messages/MessageDeclarator.h"
#include "SocketIO.h"

#include "Public.h"

class Sniffer : QObject
{
    Q_OBJECT

public:
    Sniffer();

private slots:
    void reset();
    void clientDisconnection();
    void serverDisconnection();
    void getClient();
    void processClientData();
    void processServerData();

private:
    QTcpServer m_listener;
    QTcpSocket m_server;
    QTcpSocket *m_client;
    QString m_hostAddress;
    Buffer m_serverBuffer;
    Buffer m_clientBuffer;
    bool m_expectedClientDisconnection;
    bool m_expectedServerDisconnection;
};

#endif // SNIFFER_H
