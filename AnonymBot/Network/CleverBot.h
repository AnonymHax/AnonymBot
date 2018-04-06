#ifndef CLEVERBOT_H
#define CLEVERBOT_H

#include "Public.h"
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QMessageBox>
#include <QByteArray>
#include <QUrl>
#include <QCryptographicHash>
#include <QTextDocumentFragment>
#include "SocketIO.h"


class CleverBot : public QObject
{
    Q_OBJECT
public:
    explicit CleverBot(QObject *parent = 0);
    ~CleverBot();

    void doDownload(QString mssg, QString receiver, SocketIO *sender);

    void setResponseTime(int min, int max);
    void setState(bool state);

signals:
    void hasProcessedData(SocketIO* sender,QString messageContent, QString receiver);

public slots:
    void hasFinished(QNetworkReply *reply);
    void emitAfterTimer();

private:
    QString parseReply(QString reply);
    QString parseRequest(QString req);
    QString encode(QList<QString> keyList, QList<QString> argList);
    int processTimer(QString reply);

    bool m_isActive;

    int m_minResponseTime;
    int m_maxResponseTime;

    QNetworkAccessManager *m_manager;
    QMap<QString, QString> m_headers;
    QString m_reply;
    QString m_receiver;

    QList<QString> m_keyList;
    QList<QString> m_argList;
    QByteArray m_headersId;
    QByteArray m_headersValue;

    SocketIO* m_sender;
};

#endif // CLEVERBOT_H
