#include "HelpForm.h"
#include "ui_HelpForm.h"

bool HelpForm::isAlreadyConnected = false;

HelpForm::HelpForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpForm)
{
    ui->setupUi(this);
    if (!isAlreadyConnected)
    {
        m_mail = new Smtp("anonymbotstaff@gmail.com", "anonymbot1997", "smtp.gmail.com", 465);
        QObject::connect(m_mail, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
        isAlreadyConnected = true;
    }
}

HelpForm::~HelpForm()
{
    delete ui;
}

void HelpForm::shootScreen()
{
    ui->improvement_text->setPlaceholderText("Merci de spécifier les actions a reproduire pour effectuer ce bug, la map sur laquelle cela s'est produit et le trajet que vous utilisiez.");
    m_originalPixMap = QPixmap::grabWindow(QApplication::desktop()->winId());
    updateLabel();
    saveScreen();
}

void HelpForm::updateLabel()
{
    ui->screen_label->setPixmap(m_originalPixMap.scaled(ui->screen_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void HelpForm::saveScreen()
{
    QString format = ".png";
    QString initialPath = QDir::currentPath() + tr("/tmp_bugReport") + format;

    m_filePath = initialPath;
    m_originalPixMap.save(initialPath);
}

void HelpForm::on_closeBugReport_button_clicked()
{
    close();
}

void HelpForm::on_sendBugReport_button_clicked()
{
    if (ui->improvement_text->toPlainText().isEmpty() || !isEmailAddress(ui->email_edit->text()))
    {
        QMessageBox::critical(this, "Erreur", "Vous devez remplir tous les champs et votre addresse email doit etre valide.");
        return;
    }

    QStringList path;
    QString message;
    path << m_filePath;
    message = ui->email_edit->text() + '\n' + ui->improvement_text->toPlainText();

    ui->sendBugReport_button->setText("En cours...");
    ui->sendBugReport_button->setEnabled(false);
    if (ui->screen_checkBox->checkState() == Qt::Checked)
    ui->sendBugReport_button->setText("En cours d'envoi...");

    if (ui->screen_checkBox->checkState() == Qt::Checked)
        m_mail->sendMail("anonymbotstaff@gmail.com", "anonymbotstaff@gmail.com", "Rapport bug", message, path);

    else
        m_mail->sendMail("anonymbotstaff@gmail.com", "anonymbotstaff@gmail.com", "Rapport bug", message);

    QFile f(m_filePath);
    f.remove();
}

void HelpForm::mailSent(QString message)
{
    this->setVisible(false);
    ui->improvement_text->setText("");
    ui->email_edit->setText("");

    ui->sendBugReport_button->setText("Envoyer");
    ui->sendBugReport_button->setEnabled(true);

    if (message.contains("sent"))
        QMessageBox::information(this->parentWidget(), "Merci de votre rapport", "Votre rapport a bien envoyé à l'équipe AnonymBot et nous l'examinerons dans les plus bref délais.");
    else
        QMessageBox::critical(this->parentWidget(), "Erreur", "Le rapport de rapport n'a pas pu être envoyé. Merci de vous assurer que vous êtes connecté à internet.");

    qDebug() << "HelpForm -" << message;
}

bool HelpForm::isEmailAddress(QString email) const
{
    if (email.isEmpty())
        return false;

    QRegExp regex("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
    regex.setCaseSensitivity(Qt::CaseInsensitive);
    regex.setPatternSyntax(QRegExp::RegExp);

    return regex.exactMatch(email);
}
