#ifndef SERVERHANDLER_H
#define SERVERHANDLER_H

#include "Public.h"
#include "Network/ServerBuffer.h"
#include "System/Tools/Singleton.h"
#include "AbstractServerModule.h"
#include <QSslKey>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8889
#define RECONNEXION_TIME 5000

class AbstractServerModule;

class ServerHandler : public QObject
{
    Q_OBJECT

public:
    ServerHandler();

    void init();

    void disconnect();
    bool isConnected() const;

    void addModule(AbstractServerModule *module);

    bool send(AbstractServerMessage &message);

public slots:
    void connect(bool tryUntilConnection = false);

signals:
    void serverConnectionRequest();
    void serverConnectionSuccess();
    void serverConnectionFailure();
    void serverEncryptionSuccess();
    void serverEncryptionFailure();
    void serverDisconnection(bool anticipated);

private slots:
    void processReceivedData();
    void socketDisconnection();
    void socketConnectionSucess();
    void socketConnectionFailure();
    void socketEncryptionSuccess();
    void socketEncryptionFailure();

private:
    bool m_init;
    bool m_isConnecting;
    bool m_anticipatedDisconnection;
    bool m_tryUntilConnection;
    QList<AbstractServerModule*> m_modules;
    QSslSocket m_socket;
    ServerBuffer m_buffer;
};

class ServerHandlerSingleton : public Singleton<ServerHandler>
{
};

#endif // SERVERHANDLER_H
