#include "AccountInterface.h"
#include "ui_AccountInterface.h"

AccountInterface::AccountInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountInterface)
{
    ui->setupUi(this);

    ui->accounts_view->setColumnCount(3);
    ui->accounts_view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QStringList titles;
    titles<<"Personnage"<<"Nom de compte"<<"Serveur";
    ui->accounts_view->setHorizontalHeaderLabels(titles);


    foreach(int id, D2OManagerSingleton::get()->getIndexes(GameDataTypeEnum::SERVERS))
    {
        QSharedPointer<ServerData> server = qSharedPointerCast<ServerData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SERVERS, id));
      //  if(server->getLanguage() == "fr" || server->getName() == "Oto Mustam")
            ui->servers_list->insertItem(ui->servers_list->count(), server->getName(), QString::number(server->getId()));
    }

    QFile file(USER_DATA_PATH);

    if(file.open(QFile::ReadOnly))
    {
        m_accountsData = QJsonDocument::fromBinaryData(file.readAll()).object().value("dofusAccounts").toArray();

        for(int i = 0; i < m_accountsData.size(); i++)
        {
            ConnectionInfos account;
            QVariantMap accountData = m_accountsData[i].toObject().toVariantMap();

            account.character = accountData["characterName"].toString();
            account.login = accountData["login"].toString();
            account.password = accountData["password"].toString();
            account.serverId = accountData["serverId"].toInt();
            account.server = qSharedPointerCast<ServerData>(D2OManagerSingleton::get()->getObject(GameDataTypeEnum::SERVERS, account.serverId))->getName();

            m_accounts<<account;

            int count = ui->accounts_view->rowCount();
            ui->accounts_view->setRowCount(count+1);

            ui->accounts_view->setItem(count, 0, new QTableWidgetItem(account.character));
            ui->accounts_view->setItem(count, 1, new QTableWidgetItem(account.login));
            ui->accounts_view->setItem(count, 2, new QTableWidgetItem(account.server));
        }

        file.close();
    }

    else
        qDebug()<<"Le fichier"<<USER_DATA_PATH<<"ne peut pas etre ouvert/créé";

    if (ui->accounts_view->rowCount() > 0)
    {
        ui->load_button->setEnabled(true);
        ui->accounts_view->setCurrentIndex(ui->accounts_view->indexAt(QPoint(0,0)));
    }
}

AccountInterface::~AccountInterface()
{
    delete ui;
}

QList<ConnectionInfos> AccountInterface::getAccounts() const
{
    return m_accounts;
}

void AccountInterface::on_addAccount_clicked()
{
    if (!ui->login_edit->text().isEmpty()
            && !ui->password_edit->text().isEmpty()
            && !ui->character_edit->text().isEmpty())
    {
        ConnectionInfos account;
        account.login = ui->login_edit->text();
        account.password = ui->password_edit->text();
        account.character = ui->character_edit->text();
        account.server = ui->servers_list->itemText(ui->servers_list->currentIndex());
        account.serverId = ui->servers_list->itemData(ui->servers_list->currentIndex()).toInt();

        if (!m_accounts.contains(account))
        {      
            int count = ui->accounts_view->rowCount();
            ui->accounts_view->setRowCount(count+1);

            ui->accounts_view->setItem(count, 0, new QTableWidgetItem(ui->character_edit->text()));
            ui->accounts_view->setItem(count, 1, new QTableWidgetItem(ui->login_edit->text()));
            ui->accounts_view->setItem(count, 2, new QTableWidgetItem(ui->servers_list->itemText(ui->servers_list->currentIndex())));

            m_accounts<<account;

            QJsonObject accountData;
            accountData.insert("characterName", account.character);
            accountData.insert("login", account.login);
            accountData.insert("password", account.password);
            accountData.insert("serverId", account.serverId);

            m_accountsData.append(accountData);

            QFile file(USER_DATA_PATH);

            if (file.open(QIODevice::ReadWrite))
            {
                QJsonDocument json = QJsonDocument::fromBinaryData(file.readAll());
                file.resize(0);
                QJsonObject object = json.object();
                object.insert("dofusAccounts", m_accountsData);
                json.setObject(object);
                file.write(json.toBinaryData());
                file.close();
            }

            else
                qDebug()<<"Le fichier"<<USER_DATA_PATH<<"ne peut pas etre ouvert/créé";

            if (ui->accounts_view->rowCount() != 0)
                ui->load_button->setEnabled(true);

            ui->login_edit->clear();
            ui->password_edit->clear();
            ui->character_edit->clear();
            ui->servers_list->setCurrentIndex(0);
        }
    }

    else
        QMessageBox::critical(this,"Erreur","Veuillez remplir tous les champs");
}

void AccountInterface::on_deleteAccount_clicked()
{
    QFile file(USER_DATA_PATH);
    if (file.open(QIODevice::ReadWrite))
    {
        for(int i = 0; i < m_accountsData.size(); i++)
        {
            bool include = true;

            foreach (const QModelIndex &indexModel, ui->accounts_view->selectionModel()->selectedIndexes())
            {
                if (i == indexModel.row())
                    include = false;
            }

            if(!include)
            {
                m_accountsData.removeAt(i);
                ui->accounts_view->removeRow(i);
                m_accounts.removeAt(i);
                i--;
            }
        }

        QJsonDocument json = QJsonDocument::fromBinaryData(file.readAll());
        file.resize(0);
        QJsonObject object = json.object();
        object.insert("dofusAccounts", m_accountsData);
        json.setObject(object);
        file.write(json.toBinaryData());
        file.close();

        if (ui->accounts_view->rowCount() == 0)
            ui->load_button->setEnabled(false);
    }

    else
        qDebug()<<"Le fichier"<<USER_DATA_PATH<<"ne peut pas etre ouvert/créé";
}

void AccountInterface::on_load_button_clicked()
{
    QList<ConnectionInfos> account;
    foreach (const QModelIndex &index, ui->accounts_view->selectionModel()->selectedRows())
        account<<m_accounts[index.row()];
    emit loadAccount(account);
}
