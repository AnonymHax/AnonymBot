#ifndef MAININTERFACE_H
#define MAININTERFACE_H

#include "System/ServerInteractions/SecurityModule.h"
#include "System/ServerInteractions/BotStatsModule.h"
#include "System/Tools/PropertyHelper.h"
#include "System/Engines/ProcessEngine.h"
#include "ServerConnectionInterface.h"
#include "ui_AccountInterface.h"
#include "AccountInterface.h"
#include "BotInterface.h"
#include "PathLoader.h"
#include "HelpForm.h"
#include "Public.h"
#include "Updater/fvupdater.h"


class MainInterface :  public QAbstractListModel
{
    Q_OBJECT

    AUTO_PROPERTY(QString, appName)
    AUTO_PROPERTY(bool, locked)
    AUTO_PROPERTY(int, nbActiveBots)
    AUTO_PROPERTY(QString, connectionState)
    AUTO_PROPERTY(QString, authentificationState)
    AUTO_PROPERTY(QString, authentificationIconSource)
    AUTO_PROPERTY(QString, proxyAddress)
    AUTO_PROPERTY(int, proxyPort)
    AUTO_PROPERTY(bool, proxyEnabled)

public:
    MainInterface(ProcessEngine *engine, QWidget *parent = 0);
    ~MainInterface();

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    Q_INVOKABLE BotInterface *get(int index) const;

    Q_INVOKABLE void remove(int index);
    Q_INVOKABLE void remove(BotInterface *botData);

    QVariant data(const QModelIndex & index, int role = Qt::UserRole + 1) const;

    QHash<int,QByteArray> roleNames() const;

    Q_INVOKABLE void on_manageAccounts_triggered();

    void setLock(bool locked);

private slots:

    void serverConnectionRequest();
    void serverConnectionSuccess();
    void serverConnectionFailure();
    void serverEncryptionSuccess();
    void serverEncryptionFailure();
    void serverDisconnection(bool anticipated);

    void serverAuthentificationRequest();
    void serverAuthentificationSuccess();
    void serverAuthentificationFailure(FailureReasonsEnum reason);
    void serverAuthentificationForcedDisconnection(FailureReasonsEnum reason);

    void on_managePath_triggered();
    void addAccount(const QList<ConnectionInfos> &accounts);

    void updateBotInferface(SocketIO *sender);

    void on_signalBug_triggered();
    void on_connectToServer_triggered();
    void on_displayInformations_triggered();
    void on_proxy_button_clicked(bool checked);

    void on_unloadPath_triggered();

private:
    ProcessEngine *m_engine;
    BotStatsModule *m_botStatsModule;

    HelpForm *m_bugReport;
    PathLoader *m_pathLoader;
    AccountInterface *m_accountInterface;
    QList<BotInterface*> m_botsInterfaces;
    ServerConnectionInterface *m_connectionInterface;

    QString m_login;
    QString m_password;
    bool m_hasAutoConnect;
};

#endif // MAININTERFACE_H
