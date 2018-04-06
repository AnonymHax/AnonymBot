#include "PathLoader.h"
#include "ui_PathLoader.h"

PathLoader::PathLoader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PathLoader)
{
    ui->setupUi(this);
    ui->bot_table->setColumnCount(1);
    ui->addBot_comboBox->setEditable(true);
    ui->loadFile_button->setDefault(false);
    ui->selectFile_button->setDefault(false);
    ui->selectFile_button->setDefault(false);
}

PathLoader::~PathLoader()
{
    delete ui;
}

void PathLoader::clearInterface()
{
    m_path.clear();
    m_interfaces.clear();
    ui->pathName_label->clear();
    ui->addBot_comboBox->clear();
    ui->loadFile_button->setEnabled(false);

    while (ui->bot_table->rowCount() > 0)
        ui->bot_table->removeRow(0);
}

void PathLoader::loadPath(QList<BotInterface*> interfaces)
{
    if (interfaces.isEmpty())
    {
        QMessageBox::critical(this, "Erreur", "Il faut que un ou plusieurs bots soient chargés en mémoire pour utiliser cette fonctionnalité");
        return;
    }

    clearInterface();
    m_interfaces = interfaces;
    ui->selectFile_button->setEnabled(true);
    ui->loadFile_button->setText("Charger");
    ui->addBot_comboBox->lineEdit()->setPlaceholderText("Bot sur lesquels charger le trajet");

    QList<QString> title;
    title << "Nom des bots";
    ui->bot_table->setHorizontalHeaderLabels(title);
    ui->bot_table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->bot_table->horizontalHeader()->setStretchLastSection(true);

    foreach (BotInterface *bot, interfaces)
        ui->addBot_comboBox->addItem(bot->getConnectionInfos().character);

    ui->addBot_comboBox->setCurrentIndex(-1);
    this->show();
}

void PathLoader::unloadPath(QList<BotInterface*> interfaces)
{
    if (interfaces.isEmpty())
    {
        QMessageBox::critical(this, "Erreur", "Il faut que un ou plusieurs bots soient chargés en mémoire pour utiliser cette fonctionnalité");
        return;
    }

    clearInterface();
    m_interfaces = interfaces;
    ui->selectFile_button->setEnabled(false);
    ui->loadFile_button->setText("Décharger");
    ui->addBot_comboBox->setCurrentIndex(-1);
    ui->addBot_comboBox->lineEdit()->setPlaceholderText("Bot sur lesquels décharger le trajet");

    QList<QString> title;
    title << "Nom des bots";
    ui->bot_table->setHorizontalHeaderLabels(title);
    ui->bot_table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->bot_table->horizontalHeader()->setStretchLastSection(true);


    foreach (BotInterface *bot, interfaces)
        ui->addBot_comboBox->addItem(bot->getConnectionInfos().character);

    ui->addBot_comboBox->setCurrentIndex(-1);
    this->show();
}

void PathLoader::on_selectFile_button_clicked()
{
    m_path = QFileDialog::getOpenFileName(0, "Selectionnez votre trajet à charger", "/Application");

    QFile f(m_path);
    QFileInfo i(f.fileName());
    ui->pathName_label->setText(i.fileName());
}

void PathLoader::on_loadFile_button_clicked()
{
    if (ui->loadFile_button->text() == "Charger")
    {
        bool p = false;

        QStringList list;

         for(int i = 0; i < ui->bot_table->rowCount(); i++)
         {
            list<<ui->bot_table->item(i, 0)->text();
         }

        foreach (BotInterface *bot, m_interfaces)
        {
            if(list.contains(bot->getConnectionInfos().character))
            {
                int r = bot->loadPath(m_path, false);

                if (r == INVALID)
                    QMessageBox::critical(this, "Erreur", "Nous n'avons pas réussit a ouvrir le fichier du trajet, le chargement des trajets a été interrompu veuillez recommencer après avoir corrigé l'erreur");
                else if (r != 0)
                    QMessageBox::critical(this, "Erreur", QString("Il y a une erreur à la ligne ") + QString::number(r) + QString(" ou au dessus, le chargement des trajets a été interrompu veuillez recommencer après avoir corrigé l'erreur"));

                if (r == INVALID || r != 0)
                {
                    p = true;
                    break;
                }
            }
        }

        if (!p)
            QMessageBox::information(this, "Information", "Les trajets on été chargés avec succès!");
    }

    else if (ui->loadFile_button->text() == "Décharger")
    {
        foreach (BotInterface *bot, m_interfaces)
            bot->loadPath("", true);

        QMessageBox::information(this, "Information", "Les trajets on été déchargés avec succès!");
    }

    this->hide();
    clearInterface();
}

void PathLoader::on_removeBot_button_clicked()
{
    QModelIndexList indexes = ui->bot_table->selectionModel()->selection().indexes();
    for (int i = 0; i < indexes.count(); ++i)
    {
        QModelIndex index = indexes.at(i);
        ui->bot_table->removeRow(index.row());
    }

    if (ui->bot_table->rowCount())
        ui->loadFile_button->setEnabled(true);
    else
        ui->loadFile_button->setEnabled(false);
}

void PathLoader::on_addBot_comboBox_activated(const QString &arg1)
{
    QStringList bot1, bot2;
    foreach (BotInterface *b, m_interfaces)
        bot1 << b->getConnectionInfos().character;

    for (int i = 0; i < ui->bot_table->rowCount(); i++)
        bot2 << ui->bot_table->itemAt(i, 0)->text();

    if (!bot1.contains(arg1) || bot2.contains(arg1))
        return;

    int count = ui->bot_table->rowCount();
    ui->bot_table->setRowCount(count+1);

    QTableWidgetItem *item = new QTableWidgetItem(arg1);
    item->setFlags(item->flags() ^ Qt::ItemIsEditable);
    ui->bot_table->setItem(count, 0, item);
    ui->addBot_comboBox->setCurrentIndex(-1);

    if (ui->bot_table->rowCount())
        ui->loadFile_button->setEnabled(true);
    else
        ui->loadFile_button->setEnabled(false);
}
