#ifndef HELPFORM_H
#define HELPFORM_H

#include "Public.h"
#include "Network/Smtp.h"

#include <QDesktopWidget>
#include <QDir>
#include <QScreen>
#include <QVBoxLayout>
#include <QPixmap>
#include <QMessageBox>

namespace Ui {
class HelpForm;
}

class HelpForm : public QDialog
{
    Q_OBJECT

public:
    explicit HelpForm(QWidget *parent = 0);
    ~HelpForm();

    void shootScreen();

private slots:
    void on_closeBugReport_button_clicked();
    void on_sendBugReport_button_clicked();
    void mailSent(QString message);

private:
    void saveScreen();
    void updateLabel();
    bool isEmailAddress(QString email) const;

    Smtp *m_mail;
    Ui::HelpForm *ui;
    QString m_filePath;
    QPixmap m_originalPixMap;
    static bool isAlreadyConnected;
};

#endif // HELPFORM_H
