#ifndef PATHLOADER_H
#define PATHLOADER_H

#include <QList>
#include <QDialog>
#include <QMessageBox>
#include "BotInterface.h"

namespace Ui {
class PathLoader;
}

class PathLoader : public QDialog
{
    Q_OBJECT

public:
    explicit PathLoader(QWidget *parent = 0);
    ~PathLoader();

    void clearInterface();
    void loadPath(QList<BotInterface*> interfaces);
    void unloadPath(QList<BotInterface*> interfaces);

private slots:
    void on_loadFile_button_clicked();
    void on_removeBot_button_clicked();
    void on_selectFile_button_clicked();
    void on_addBot_comboBox_activated(const QString &arg1);

private:
    QString m_path;
    Ui::PathLoader *ui;
    QList<BotInterface*> m_interfaces;
};

#endif // PATHLOADER_H
