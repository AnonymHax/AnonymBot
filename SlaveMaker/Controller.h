#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QtSql>
#include "Network/DofusMessages/DofusServer.h"
#include "Network/DofusMessages/RawDataMessage.h"
#include "Network/DofusMessages/CheckIntegrityMessage.h"
#include "Network/ServerMessages/ServerBuffer.h"
#include "Network/ServerMessages/RawResolveFailureMessage.h"
#include "Network/ServerMessages/RawResolveRequestMessage.h"
#include "Network/ServerMessages/RawResolveMessage.h"
#include "Network/ServerMessages/ConnectionRequestMessage.h"
#include "Network/ServerMessages/ConnectionFailureMessage.h"
#include "Network/ServerMessages/ConnectionSuccessMessage.h"
#include "Network/ServerMessages/ClientUpdateMessage.h"
#include "Network/ServerMessages/ServerUpdateMessage.h"
#include "Network/ServerMessages/ForceDisconnectionMessage.h"
#include "Network/ServerMessages/SecureServer.h"

#define SERVER_PORT 8889

struct RawDataTranslateRequest
{
    QList<int> indexes;
};

struct ConnectedAccount
{
    ServerBuffer buffer;
    QString login;
    RawDataTranslateRequest rawRequest;
    uint nbActiveBots = 0;
};

bool operator==(const ConnectedAccount &left, const ConnectedAccount &right);


class Controller : public QObject
{

    Q_OBJECT

public:
    Controller();
    ~Controller();

public slots:
    void addConnection();
    void connectionEncryptionSuccess();
    void connectionEncryptionFailure(QList<QSslError> errors);
    void connectionError();
    void removeConnection();
    void processBotData();
    void processDofusData(QList<DofusMessageInfos> messages);
    void reset();
    void updateStats();

private:
    bool m_isProcessing;
    DofusServer m_dofusServer;
    SecureServer m_botServer;
    QList<QSslSocket*> m_waitingForRaw;
    QHash<QSslSocket*, ConnectedAccount> m_connectedAccounts;
    QTimer m_timer;
    uint m_totalNbActiveBots;
    QSqlDatabase m_dataBase;
};

#endif // CONTROLLER_H
