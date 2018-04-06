#include "MainInterface.h"
#include "ui_MainInterface.h"

MainInterface::MainInterface(ProcessEngine *engine, QWidget *parent) :
    m_engine(engine),
    m_hasAutoConnect(false)
{
    QTime t;
    t.start();

    FvUpdater::sharedUpdater()->SetFeedURL("http://anonymbot.com/maj/appcast.xml");
    FvUpdater::sharedUpdater()->CheckForUpdatesSilent();

    //ui->setupUi(this);

    appName("AnonymBot");
    locked(false);
    nbActiveBots(0);
    connectionState("Déconnecté");
    authentificationState("Non authentifié");
    authentificationIconSource(":/Resources/red.png");
    proxyPort(5555);
    proxyEnabled(false);

    connect(ServerHandlerSingleton::get(), SIGNAL(serverConnectionRequest()), this, SLOT(serverConnectionRequest()));
    connect(ServerHandlerSingleton::get(), SIGNAL(serverDisconnection(bool)), this, SLOT(serverDisconnection(bool)));
    connect(ServerHandlerSingleton::get(), SIGNAL(serverConnectionSuccess()), this, SLOT(serverConnectionSuccess()));
    connect(ServerHandlerSingleton::get(), SIGNAL(serverConnectionFailure()), this, SLOT(serverConnectionFailure()));
    connect(ServerHandlerSingleton::get(), SIGNAL(serverEncryptionSuccess()), this, SLOT(serverEncryptionSuccess()));
    connect(ServerHandlerSingleton::get(), SIGNAL(serverEncryptionFailure()), this, SLOT(serverEncryptionFailure()));

    connect(SecurityModuleSingleton::get(), SIGNAL(serverAuthentificationRequest()), this, SLOT(serverAuthentificationRequest()));
    connect(SecurityModuleSingleton::get(), SIGNAL(serverAuthentificationSuccess()), this, SLOT(serverAuthentificationSuccess()));
    connect(SecurityModuleSingleton::get(), SIGNAL(serverAuthentificationForcedDisconnection(FailureReasonsEnum)), this, SLOT(serverAuthentificationForcedDisconnection(FailureReasonsEnum)));
    connect(SecurityModuleSingleton::get(), SIGNAL(serverAuthentificationFailure(FailureReasonsEnum)), this, SLOT(serverAuthentificationFailure(FailureReasonsEnum)));

    ServerHandlerSingleton::get()->connect();

    connect(m_engine, SIGNAL(informationsUpdated(SocketIO*)), this, SLOT(updateBotInferface(SocketIO*)));

    m_connectionInterface = new ServerConnectionInterface();

    m_accountInterface = new AccountInterface();
    connect(m_accountInterface, SIGNAL(loadAccount(const QList<ConnectionInfos>&)), this, SLOT(addAccount(const QList<ConnectionInfos>&)));

    m_pathLoader = new PathLoader();
    m_bugReport = new HelpForm();

    qDebug()<<"MainInterface - Initialisation - Temps écoulé:"<<t.elapsed()<<"ms";
}

MainInterface::~MainInterface()
{
    foreach(BotInterface *botInterface, m_botsInterfaces)
        delete botInterface;

    delete m_engine;
    delete m_bugReport;
    delete m_pathLoader;
    delete m_accountInterface;
}


int MainInterface::rowCount(const QModelIndex &) const
{
    return m_botsInterfaces.size();
}

BotInterface* MainInterface::get(int index) const
{
    if(m_botsInterfaces.size()-1 >= index)
        return m_botsInterfaces[index];

    else
        return NULL;
}

void MainInterface::remove(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    delete m_botsInterfaces[index];
    m_botsInterfaces.removeAt(index);
    endRemoveRows();
}

void MainInterface::remove(BotInterface *botData)
{
    int index = m_botsInterfaces.indexOf(botData);
    remove(index);
}

QVariant MainInterface::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() > m_botsInterfaces.count())
        qDebug()<<"ERREUR - MainInterface - Index incorrect"<<index.row();

    if (role == Qt::UserRole + 1)
        return qVariantFromValue(m_botsInterfaces[index.row()]);
    else
        qDebug()<<"ERREUR - MainInterface - Role inconnu demandé"<<role;
}

QHash<int, QByteArray> MainInterface::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::UserRole + 1] = "botData";
    return roles;
}

void MainInterface::setLock(bool _locked)
{
    locked(_locked);

    if(_locked)
      appName("AnonymBot");

    else
    {
        if(SecurityModuleSingleton::get()->getAccountType() == AccountTypeEnum::TRIAL)
            appName("AnonymBot - Compte d'essaie");

        else if(SecurityModuleSingleton::get()->getAccountType() == AccountTypeEnum::PREMIUM)
            appName("AnonymBot - Compte Premium");
    }
}

void MainInterface::serverConnectionRequest()
{
    authentificationIconSource(":/Resources/orange.png");
    connectionState("Connexion");
}

void MainInterface::serverConnectionSuccess()
{
    authentificationIconSource(":/Resources/orange.png");
    connectionState("Connecté");
}

void MainInterface::serverConnectionFailure()
{
    authentificationIconSource(":/Resources/red.png");
    connectionState("Echec de connexion");
    setLock(true);
}

void MainInterface::serverDisconnection(bool anticipated)
{
    authentificationIconSource(":/Resources/red.png");
    authentificationState("Non authentifié");

    if(anticipated)
      connectionState("Déconnecté");

    else
        connectionState("Rupture de la connexion");

    setLock(true);
}

void MainInterface::serverEncryptionSuccess()
{
    authentificationIconSource(":/Resources/orange.png");
    connectionState("Connecté (Sécurisé)");

    if(!m_hasAutoConnect)
    {
        m_hasAutoConnect = true;
        m_connectionInterface->on_connect_button_clicked();
    }
}

void MainInterface::serverEncryptionFailure()
{
    authentificationIconSource(":/Resources/red.png");
    connectionState("Echec encryption");
    setLock(true);
}

void MainInterface::serverAuthentificationRequest()
{
    if(ServerHandlerSingleton::get()->isConnected())
    {
        authentificationIconSource(":/Resources/orange.png");
        authentificationState("Authentification");
    }
}

void MainInterface::serverAuthentificationSuccess()
{
    authentificationIconSource(":/Resources/green.png");
    authentificationState("Authentifié");
    setLock(false);
}

void MainInterface::serverAuthentificationFailure(FailureReasonsEnum reason)
{
    authentificationIconSource(":/Resources/orange.png");
    authentificationState("Echec de l'authentification");
    setLock(true);
}

void MainInterface::serverAuthentificationForcedDisconnection(FailureReasonsEnum reason)
{
    authentificationIconSource(":/Resources/orange.png");

    if(reason == FailureReasonsEnum::MULTIPLECONNECTION)
        authentificationState("Le compte est utilisé par un autre client");

    else
        authentificationState("Le serveur à demandé la déconnexion de ce compte");

    setLock(true);
}

void MainInterface::on_connectToServer_triggered()
{
    m_connectionInterface->show();
}

void MainInterface::on_manageAccounts_triggered()
{
    if(!m_pathLoader->isVisible())
        m_accountInterface->show();
}

void MainInterface::on_managePath_triggered()
{
    if(!m_accountInterface->isVisible())
        m_pathLoader->loadPath(m_botsInterfaces);
}

void MainInterface::addAccount(const QList<ConnectionInfos> &accounts)
{  
    bool alreadyExist = false;

    foreach(BotInterface *botInterface, m_botsInterfaces)
    {
        foreach (const ConnectionInfos &account, accounts)
        {
            if (botInterface->getConnectionInfos().character == account.character)
                alreadyExist = true;
        }
    }

    if (alreadyExist)
    {
        QMessageBox::critical(NULL,"Erreur","Le compte est déjà chargé en mémoire");
        m_accountInterface->close();
    }

    else
    {
        m_accountInterface->close();
        foreach (ConnectionInfos account, accounts)
        {
            beginInsertRows(QModelIndex(), m_botsInterfaces.size(), m_botsInterfaces.size());
            m_botsInterfaces<< new BotInterface(m_engine, account);
            endInsertRows();

        //    ui->bots_tabs->addTab(m_botsInterfaces.last(),QIcon(),account.character);
          //  ui->bots_tabs->setCurrentIndex(m_botsInterfaces.size()-1);
        }
    }
}

void MainInterface::updateBotInferface(SocketIO *sender)
{
    foreach(BotInterface *botInterface, m_botsInterfaces)
    {
        if (botInterface->getSocket() == sender)
        {
            botInterface->updateInterface();
            break;
        }
    }
}


void MainInterface::on_proxy_button_clicked(bool checked)
{
    ProxyInfos proxy;

    if(checked)
    {
        //ui->proxyAdress_edit->setEnabled(true);
        //ui->proxyPort_spin->setEnabled(true);
        proxy.adress = proxyAddress();
        proxy.port = proxyPort();

        proxy.type = QNetworkProxy::Socks5Proxy;
    }

    else
    {
       // ui->proxyAdress_edit->setEnabled(false);
       // ui->proxyPort_spin->setEnabled(false);
    }

    SocketIO::setProxy(proxy);
}

void MainInterface::on_signalBug_triggered()
{
    m_bugReport->shootScreen();
    m_bugReport->show();
}

void MainInterface::on_displayInformations_triggered()
{
    QMessageBox::about(NULL, "A propos du bot", "<html><head/><body>Ce bot est developé par AnonymHax et G0hu\n<p align=\"center\">Version "+QApplication::applicationVersion()+"</p></body></html>");
    QMessageBox messageBox;
    messageBox.setText("<html><head/><body>Ce bot est developé par AnonymHax et G0hu\n<p align=\"center\">Version "+QApplication::applicationVersion()+"</p></body></html>");
    QAbstractButton *checkUpdates =
          messageBox.addButton(tr("Vérifier mises à jour"), QMessageBox::ActionRole);

    messageBox.exec();
    if (messageBox.clickedButton() == checkUpdates)
        FvUpdater::sharedUpdater()->CheckForUpdatesNotSilent();
}

void MainInterface::on_unloadPath_triggered()
{
    if(!m_accountInterface->isVisible())
        m_pathLoader->unloadPath(m_botsInterfaces);
}
