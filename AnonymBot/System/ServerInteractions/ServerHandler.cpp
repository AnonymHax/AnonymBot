#include "ServerHandler.h"
#include "AbstractServerModule.h"


ServerHandler::ServerHandler():
    m_isConnecting(false),
    m_anticipatedDisconnection(false),
    m_tryUntilConnection(false),
    m_init(false)
{
    m_socket.setProtocol(QSsl::SslV3);

    QObject::connect(&m_socket, SIGNAL(readyRead()), this, SLOT(processReceivedData()));
    QObject::connect(&m_socket, SIGNAL(disconnected()), this, SLOT(socketDisconnection()));
    QObject::connect(&m_socket, SIGNAL(connected()), this, SLOT(socketConnectionSucess()));
    QObject::connect(&m_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(socketConnectionFailure()));
    QObject::connect(&m_socket, SIGNAL(encrypted()), this, SLOT(socketEncryptionSuccess()));
    QObject::connect(&m_socket, SIGNAL(sslErrors(QList<QSslError>)), this, SLOT(socketEncryptionFailure()));
}

void ServerHandler::init()
{
    if(!m_init)
    {
        QTime t;
        t.start();

        m_init = true;

        QFile certificateData(":/Resources/server.crt");

        if(!certificateData.open(QIODevice::ReadOnly))
            qDebug()<<"ERREUR - ServerHandler - L'ouverture du certificat a échouée";

        QSslCertificate certificate(certificateData.readAll());
        m_socket.addCaCertificate(certificate);

        qDebug()<<"ServerHandler - Initialisation - Temps écoulé:"<<t.elapsed()<<"ms";
    }
}

void ServerHandler::disconnect()
{
    m_anticipatedDisconnection = true;
    m_isConnecting = false;
    m_socket.disconnectFromHost();
}

bool ServerHandler::isConnected() const
{
    if(m_socket.state() == QAbstractSocket::ConnectedState && m_socket.mode() == QSslSocket::SslClientMode)
        return true;

    return false;
}

void ServerHandler::addModule(AbstractServerModule *module)
{
    m_modules<<module;
}

bool ServerHandler::send(AbstractServerMessage &message)
{
    if(isConnected())
    {
        m_socket.write(m_buffer.writePacket(message).getBuffer());
        return true;
    }

    qDebug()<<"ERREUR - ServerHandler - On tente d'envoyer un message alors que le bot n'est pas connecté au serveur";
    return false;
}

void ServerHandler::connect(bool tryUntilConnection)
{
    init();

    if(m_socket.state() == QAbstractSocket::UnconnectedState)
    {
        if(!m_tryUntilConnection)
             m_tryUntilConnection = tryUntilConnection;

         m_socket.connectToHostEncrypted(SERVER_IP, SERVER_PORT);
         m_isConnecting = true;
         emit serverConnectionRequest();
    }
}

void ServerHandler::processReceivedData()
{
    QList<ServerMessageInfos> messages = m_buffer.readPacket(m_socket.readAll());

    foreach(const ServerMessageInfos &message, messages)
    {
        foreach(AbstractServerModule *module, m_modules)
        {
            if(module->processMessage(message))
                break;
        }
    }
}

void ServerHandler::socketConnectionFailure()
{
    if(m_isConnecting)
    {
        emit serverConnectionFailure();

        qDebug()<<"ERREUR - ServerHandler - La connexion avec AnonymServer échouée - Raison :"<<m_socket.errorString();

        foreach(AbstractServerModule *module, m_modules)
            module->serverConnectionFailed();

        if(m_tryUntilConnection)
        {
            QTimer::singleShot(RECONNEXION_TIME, this, SLOT(connect()));
            qDebug()<<"Tentative de reconnexion dans"<<RECONNEXION_TIME/1000<<"s";
        }
    }

    m_isConnecting = false;
}

void ServerHandler::socketConnectionSucess()
{
    m_isConnecting = false;
    emit serverConnectionSuccess();
    qDebug() << "ServerHandler - Succès de connexion à AnonymServer, attente de l'encryption";
    m_socket.ignoreSslErrors(); // todo: A retirer pour la release
}

void ServerHandler::socketDisconnection()
{
    m_isConnecting = false;
    emit serverDisconnection(m_anticipatedDisconnection);

    foreach(AbstractServerModule *module, m_modules)
        module->serverDisconnected(m_anticipatedDisconnection);

    if(!m_anticipatedDisconnection || m_tryUntilConnection)
    {
        m_tryUntilConnection = true;
        QTimer::singleShot(RECONNEXION_TIME, this, SLOT(connect()));
        qDebug()<<m_socket.errorString();
        qDebug()<<"ERREUR - ServerHandler - Rupture de connexion avec AnonymServer";
        qDebug()<<"Tentative de reconnexion dans"<<RECONNEXION_TIME/1000<<"s";
    }

    else
    {
        m_anticipatedDisconnection = false;
        qDebug()<<"ServerHandler - Connexion avec AnonymServer terminée";
    }

}

void ServerHandler::socketEncryptionSuccess()
{
    m_tryUntilConnection = false;
    m_isConnecting = false;
    emit serverEncryptionSuccess();

    qDebug()<<"ServerHandler - Connexion avec AnonymServer encryptée - communication prete";

    foreach(AbstractServerModule *module, m_modules)
        module->serverConnectionEstablished();
}

void ServerHandler::socketEncryptionFailure()
{
    m_isConnecting = false;
    emit serverEncryptionFailure();

    qDebug()<<"ServerHandler - Erreur(s) SSL -"<<m_socket.sslErrors();

    foreach(AbstractServerModule *module, m_modules)
        module->serverConnectionFailed();

    if(m_tryUntilConnection)
    {
        QTimer::singleShot(RECONNEXION_TIME, this, SLOT(connect()));
        qDebug()<<"Tentative de reconnexion dans"<<RECONNEXION_TIME/1000<<"s";
    }
}
