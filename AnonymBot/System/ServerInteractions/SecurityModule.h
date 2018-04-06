#ifndef SECURITYMODULE_H
#define SECURITYMODULE_H

#include "Public.h"
#include "AbstractServerModule.h"
#include "System/Tools/Singleton.h"
#include "Network/ServerMessages/ConnectionRequestMessage.h"
#include "Network/ServerMessages/ConnectionFailureMessage.h"
#include "Network/ServerMessages/ConnectionSuccessMessage.h"
#include "Network/ServerMessages/ForceDisconnectionMessage.h"

class SecurityModule : public QObject, public AbstractServerModule
{

    Q_OBJECT

public:
    SecurityModule();

    bool processMessage(const ServerMessageInfos &data);

    void connect();
    void setCredentials(QString login, QString password);

    bool isAuthentificated() const;
    AccountTypeEnum getAccountType() const;

    virtual void serverConnectionFailed();
    virtual void serverDisconnected(bool anticipatedDisconnection);

private slots:
    void autoConnect();

signals:
    void serverAuthentificationRequest();
    void serverAuthentificationFailure(FailureReasonsEnum reason);
    void serverAuthentificationSuccess();
    void serverAuthentificationForcedDisconnection(FailureReasonsEnum reason);
    void serverReadyToAuthentificate();

private:    
    QString m_login;
    QString m_password;
    AccountTypeEnum m_accountType;
    QDate m_leftTime;
    bool m_hasRequestedAuthentification;
    bool m_isAuthentificated;
};

class SecurityModuleSingleton : public Singleton<SecurityModule>
{
};

#endif // SECURITYMODULE_H
