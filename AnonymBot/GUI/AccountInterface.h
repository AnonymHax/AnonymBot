#ifndef ACCOUNTINTERFACE_H
#define ACCOUNTINTERFACE_H

#include "Public.h"
#include "System/Engines/CoreEngine.h"
#include "System/Tools/IO/D2O/D2OManager.h"

namespace Ui {
class AccountInterface;
}

class AccountInterface : public QDialog
{
    Q_OBJECT

public:
    explicit AccountInterface(QWidget *parent = 0);
    ~AccountInterface();

    QList<ConnectionInfos> getAccounts() const;

signals:
    void loadAccount(const QList<ConnectionInfos>&);

private slots:
    void on_addAccount_clicked();
    void on_deleteAccount_clicked();
    void on_load_button_clicked();

private:
    Ui::AccountInterface *ui;
    QList<ConnectionInfos> m_accounts;
    QJsonArray m_accountsData;
};

#endif // ACCOUNTINTERFACE_H
