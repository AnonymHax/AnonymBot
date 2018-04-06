#ifndef SERVERCONNECTIONINTERFACE_H
#define SERVERCONNECTIONINTERFACE_H

#include "Public.h"
#include "System/ServerInteractions/SecurityModule.h"

namespace Ui {
class ServerConnectionInterface;
}

class ServerConnectionInterface : public QDialog
{
    Q_OBJECT

public:
    explicit ServerConnectionInterface(QWidget *parent = 0);
    ~ServerConnectionInterface();

public slots:
    void serverDisconnection(bool anticipated);
    void serverConnectionFailure();
    void serverEncryptionFailure();

    void serverAuthentificationRequest();
    void serverAuthentificationSuccess();
    void serverAuthentificationFailure(FailureReasonsEnum reason);

    void on_connect_button_clicked();

private slots:
    void on_login_edit_textChanged(const QString &text);
    void on_password_edit_textChanged(const QString &text);

private:
    Ui::ServerConnectionInterface *ui;
};

#endif // SERVERCONNECTIONINTERFACE_H
