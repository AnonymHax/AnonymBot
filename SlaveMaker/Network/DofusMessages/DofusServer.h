#ifndef DOFUSSERVER_H
#define DOFUSSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include "RawDataMessage.h"
#include "DofusBuffer.h"
#include "BasicLatencyStatsRequestMessage.h"

class DofusServer : public QObject
{
    Q_OBJECT

public:
    DofusServer();
    ~DofusServer();

public slots:
    void connectionRequested();
    bool sendMessage(AbstractDofusMessage &message);
    void socketReadyRead();
    void socketDisconnected();

    bool isConnected() const;

signals:
    void dataReceived(QList<DofusMessageInfos> messages);
    void serverDisconnected();

private:
    QTcpServer *m_server;
    QTcpSocket *m_client;
    DofusBuffer m_buffer;
    QList<QString> m_addresses;
};

#endif // DOFUSSERVER_H
