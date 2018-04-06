#include "ServerConnectionInterface.h"
#include "ui_ServerConnectionInterface.h"

ServerConnectionInterface::ServerConnectionInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServerConnectionInterface)
{
    ui->setupUi(this);

    ui->error_label->setVisible(false);

    connect(ServerHandlerSingleton::get(), SIGNAL(serverDisconnection(bool)), this, SLOT(serverDisconnection(bool)));
    connect(ServerHandlerSingleton::get(), SIGNAL(serverConnectionFailure()), this, SLOT(serverConnectionFailure()));
    connect(ServerHandlerSingleton::get(), SIGNAL(serverEncryptionFailure()), this, SLOT(serverEncryptionFailure()));

    connect(SecurityModuleSingleton::get(), SIGNAL(serverAuthentificationRequest()), this, SLOT(serverAuthentificationRequest()));
    connect(SecurityModuleSingleton::get(), SIGNAL(serverAuthentificationSuccess()), this, SLOT(serverAuthentificationSuccess()));
    connect(SecurityModuleSingleton::get(), SIGNAL(serverAuthentificationFailure(FailureReasonsEnum)), this, SLOT(serverAuthentificationFailure(FailureReasonsEnum)));

    QFile file(USER_DATA_PATH);

    if (file.open(QFile::ReadOnly))
    {
        QJsonObject object = QJsonDocument::fromBinaryData(file.readAll()).object().value("anonymBotAccount").toObject();
        ui->login_edit->setText(object.value("login").toString());
        ui->password_edit->setText(object.value("password").toString());
        ui->rememberPassword_checkBox->setChecked(object.value("rememberPassword").toBool(true));
    }

    else
        qDebug()<<"Le fichier"<<USER_DATA_PATH<<"ne peut pas etre ouvert, il est peut-etre manquant";

    if(ui->login_edit->text().isEmpty())
        ui->login_edit->setFocus();

    else if(ui->password_edit->text().isEmpty())
        ui->password_edit->setFocus();
}

ServerConnectionInterface::~ServerConnectionInterface()
{
    delete ui;
}

void ServerConnectionInterface::serverDisconnection(bool anticipated)
{
    ui->connect_button->setText("Connecter");
    ui->connect_button->setEnabled(true);
    ui->login_edit->setEnabled(true);
    ui->password_edit->setEnabled(true);

    if(!anticipated)
    {
        ui->error_label->setText("<font color=red>La connection a été interrompue</font>");
        ui->error_label->setVisible(true);
    }
}

void ServerConnectionInterface::serverConnectionFailure()
{
    if(!ui->connect_button->isEnabled())
    {
        ui->connect_button->setText("Connecter");
        ui->connect_button->setEnabled(true);
        ui->login_edit->setEnabled(true);
        ui->password_edit->setEnabled(true);

        ui->error_label->setText("<font color=red>Echec lors de la connexion au serveur</font>");
        ui->error_label->setVisible(true);
    }
}

void ServerConnectionInterface::serverEncryptionFailure()
{
    ui->connect_button->setText("Connecter");
    ui->connect_button->setEnabled(true);
    ui->login_edit->setEnabled(true);
    ui->password_edit->setEnabled(true);

    ui->error_label->setText("<font color=red>Erreur lors de la connection au serveur</font>");
    ui->error_label->setVisible(true);
}

void ServerConnectionInterface::serverAuthentificationRequest()
{
    ui->connect_button->setText("Connection en cours...");
    ui->connect_button->setEnabled(false);
    ui->login_edit->setEnabled(false);
    ui->password_edit->setEnabled(false);
    ui->error_label->setVisible(false);
}

void ServerConnectionInterface::serverAuthentificationSuccess()
{
    ui->error_label->setVisible(false);
    ui->connect_button->setText("Déconnecter");
    ui->connect_button->setEnabled(true);
    close();
}

void ServerConnectionInterface::serverAuthentificationFailure(FailureReasonsEnum reason)
{
    ui->connect_button->setText("Connecter");
    ui->connect_button->setEnabled(true);
    ui->login_edit->setEnabled(true);
    ui->password_edit->setEnabled(true);

    if(reason == FailureReasonsEnum::WRONGCREDENTIALS)
    {
        ui->error_label->setVisible(true);
        ui->error_label->setText("<font color=red>Identifiants incorrects</font>");


        if(!ui->password_edit->text().isEmpty())
        {
            ui->password_edit->setFocus();
            ui->password_edit->selectAll();
       }
    }

    else if(reason == FailureReasonsEnum::UNKNOWN)
    {
        ui->error_label->setVisible(true);
        ui->error_label->setText("<font color=red>Une erreur inconnue est survenue</font>");
    }

    show();
}

void ServerConnectionInterface::on_connect_button_clicked()
{
    if(ui->login_edit->text().isEmpty() || ui->password_edit->text().isEmpty())
    {
        if(ui->login_edit->text().isEmpty())
            ui->login_edit->setFocus();

        else if(ui->password_edit->text().isEmpty())
            ui->password_edit->setFocus();

        show();
    }

    else if(!SecurityModuleSingleton::get()->isAuthentificated())
    {
        QFile file(USER_DATA_PATH);

        if (file.open(QIODevice::ReadWrite))
        {
            QJsonDocument json = QJsonDocument::fromBinaryData(file.readAll());
            file.resize(0);
            QJsonObject object = json.object();
            QJsonObject connectionObject;

            connectionObject.insert("login", ui->login_edit->text());

            if(ui->rememberPassword_checkBox->isChecked())
                connectionObject.insert("password", ui->password_edit->text());

            else
                connectionObject.insert("password", "");

            connectionObject.insert("rememberPassword", ui->rememberPassword_checkBox->isChecked());

            object.insert("anonymBotAccount", connectionObject);

            json.setObject(object);
            file.write(json.toBinaryData());
            file.close();
        }

        else
            qDebug()<<"Le fichier"<<USER_DATA_PATH<<"ne peut pas etre ouvert, il est peut-etre manquant";


        ui->error_label->setVisible(false);
        ui->login_edit->setEnabled(false);
        ui->password_edit->setEnabled(false);

        SecurityModuleSingleton::get()->setCredentials(ui->login_edit->text(), ui->password_edit->text());
        SecurityModuleSingleton::get()->connect();

        ui->connect_button->setText("Connection en cours...");
        ui->connect_button->setEnabled(false);
        ui->error_label->setVisible(false);
    }

    else
        ServerHandlerSingleton::get()->disconnect();
}

void ServerConnectionInterface::on_login_edit_textChanged(const QString &text)
{
    ui->connect_button->setEnabled(!text.isEmpty() && !ui->password_edit->text().isEmpty());
}

void ServerConnectionInterface::on_password_edit_textChanged(const QString &text)
{
    ui->connect_button->setEnabled(!text.isEmpty() && !ui->login_edit->text().isEmpty());
}
