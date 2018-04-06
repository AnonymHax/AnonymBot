#include "SecurityModule.h"

SecurityModule::SecurityModule():
    m_isAuthentificated(false),
    m_hasRequestedAuthentification(false)
{
}

bool SecurityModule::processMessage(const ServerMessageInfos &data)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case ServerMessageEnum::CONNECTIONSUCCESSMESSAGE:
    {
        ConnectionSuccessMessage message;
        message.deserialize(&reader);

        m_accountType = message.accountType;

        m_hasRequestedAuthentification = false;
        m_isAuthentificated = true;

        emit serverAuthentificationSuccess();
    }
        break;

    case ServerMessageEnum::CONNECTIONFAILUREMESSAGE:
    {
        ConnectionFailureMessage message;
        message.deserialize(&reader);

        m_hasRequestedAuthentification = false;
        m_isAuthentificated = false;

        ServerHandlerSingleton::get()->disconnect();
        emit serverAuthentificationFailure(message.reason);
    }
        break;

    case ServerMessageEnum::FORCEDISCONNECTIONMESSAGE:
    {
        ForceDisconnectionMessage message;
        message.deserialize(&reader);

        m_hasRequestedAuthentification = false;
        m_isAuthentificated = false;

        ServerHandlerSingleton::get()->disconnect();
        emit serverAuthentificationForcedDisconnection(message.reason);
    }
        break;


    }

    return messageFound;
}

void SecurityModule::connect()
{
    if(!m_login.isEmpty() && !m_password.isEmpty() && !m_hasRequestedAuthentification && ServerHandlerSingleton::get()->isConnected())
    {
        ConnectionRequestMessage answer;
        answer.login = m_login;
        answer.password = m_password;
        ServerHandlerSingleton::get()->send(answer);
        m_hasRequestedAuthentification = true;
        emit serverAuthentificationRequest();
    }

    else if(!m_login.isEmpty() && !m_password.isEmpty() && !m_hasRequestedAuthentification && !ServerHandlerSingleton::get()->isConnected())
    {
        m_hasRequestedAuthentification = true;
        QObject::connect(ServerHandlerSingleton::get(), SIGNAL(serverEncryptionSuccess()), this, SLOT(autoConnect()));
        ServerHandlerSingleton::get()->connect();
        emit serverAuthentificationRequest();
    }
}

void SecurityModule::setCredentials(QString login, QString password)
{
    m_login = login;
    m_password = password;
}

bool SecurityModule::isAuthentificated() const
{
   // if(m_isAuthentificated && ServerHandlerSingleton::get()->isConnected())
        return true;

    return false;
}

AccountTypeEnum SecurityModule::getAccountType() const
{
    return m_accountType;
}

void SecurityModule::serverConnectionFailed()
{
    m_hasRequestedAuthentification = false;
}

void SecurityModule::serverDisconnected(bool anticipatedDisconnection)
{
    if(!anticipatedDisconnection)
    {
        QObject::connect(ServerHandlerSingleton::get(), SIGNAL(serverEncryptionSuccess()), this, SLOT(autoConnect()));
        emit serverAuthentificationRequest();
    }

    // TODO: Changer to FALSE pour la release
    m_isAuthentificated = true;
}

void SecurityModule::autoConnect()
{
    disconnect(ServerHandlerSingleton::get(), SIGNAL(serverEncryptionSuccess()), this, SLOT(autoConnect()));
    emit serverAuthentificationRequest();

    ConnectionRequestMessage answer;
    answer.login = m_login;
    answer.password = m_password;
    ServerHandlerSingleton::get()->send(answer);
}
