#include "CleverBot.h"
#include <QTextDocument>
#include <iostream>

CleverBot::CleverBot(QObject *parent) :
    QObject(parent),
    m_minResponseTime(0),
    m_maxResponseTime(7),
    m_isActive(true)
{
    m_manager = new QNetworkAccessManager(this);

    QObject::connect(m_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(hasFinished(QNetworkReply*)));

    m_headersId.append("User-Agent");
    m_headersId.append("Accept");
    m_headersId.append("Accept-Language");
    m_headersId.append("Accept-Charset");
    m_headersId.append("Referer");
    m_headersId.append("Cache-Control");
    m_headersId.append("Pragma");

    m_headersValue.append("Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/33.0.1750.146 Safari/537.36");
    m_headersValue.append("text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
    m_headersValue.append("fr-fr");
    m_headersValue.append("ISO-8859-1,utf-8;q=0.7,*;q=0.7");
    m_headersValue.append("http://www.cleverBot.com/webserviceadmin/");
    m_headersValue.append("no-cache");
    m_headersValue.append("no-cache");

    m_argList<<""<<"y"<<""<<""<<""<<""<<""<<""<<""<<""<<"wsf"<<""<<""<<""<<""<<""<<""<<""<<""<<"0"<<"Say"<<"1"
            <<"false"<<""<<""<<""<<""<<""<<""<<""<<"";
    m_keyList<<"stimulus"<<"start"<<"sessionid"<<"vText8"<<"vText7"<<"vText6"<<"vText5"<<"vText4"<<"vText3"
            <<"vText2"<<"icognoid"<<"icognocheck"<<"prevref"<<"emotionaloutput"<<"emotionalhistory"<<"lineRef"
           <<"fno"<<"sub"<<"islearning"<<"cleanslate"<<"logurl"<<"ttsLocTXT"<<"ttsLocTXT3"<<"ttsText"<<"lineURL"
          <<"linePOST"<<"lineChoices"<<"lineChoicesAbbrev"<<"typingData"<<"divert"<<"ttsLocMP3";
}

CleverBot::~CleverBot()
{
    delete m_manager;
}

void CleverBot::doDownload(QString mssg, QString receiver, SocketIO *sender)
{
    if(m_isActive)
    {
        m_receiver = receiver;
        m_sender = sender;

        QString link;
        link = "http://www.cleverBot.com/webservicemin/";
        mssg = parseRequest(mssg);
        m_argList[m_keyList.indexOf("stimulus")] = QString(QUrl::toPercentEncoding(mssg));

        QUrl tmp(link);
        QNetworkRequest req(tmp);
        req.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
        req.setRawHeader(m_headersId, m_headersValue);

        QString data = encode(m_keyList, m_argList);
        QString digest_txt = data.mid(9, 26);
        QByteArray tmpData;
        QByteArray dataToSend;

        tmpData.append(digest_txt);
        QString hash = QString(QCryptographicHash::hash((QByteArray(tmpData)), QCryptographicHash::Md5).toHex());
        m_argList[m_keyList.indexOf("icognocheck")] = hash;
        data = encode(m_keyList, m_argList);
        dataToSend.append(data);

        m_manager->post(req, dataToSend);
    }
}

void CleverBot::setResponseTime(int min, int max)
{
    m_minResponseTime = min;
    m_maxResponseTime = max;
}

void CleverBot::setState(bool state)
{
    m_isActive = state;
}

void CleverBot::hasFinished(QNetworkReply *reply)
{
    m_reply.clear();

    if(reply->error())
    {
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();
    }

    else
    {
        m_reply = QString(reply->readAll());
        m_reply = parseReply(m_reply);
        QTimer::singleShot(processTimer(m_reply), this, SLOT(emitAfterTimer()));
    }

    reply->deleteLater();
}

QString CleverBot::parseReply(QString reply)
{
    QStringList parsed = reply.split('\r');

    m_argList[m_keyList.indexOf("sessionid")];
    m_argList[m_keyList.indexOf("sessionid")] = parsed[1];
    m_argList[m_keyList.indexOf("logurl")] = parsed[2];
    m_argList[m_keyList.indexOf("vText8")] = parsed[3];
    m_argList[m_keyList.indexOf("vText7")] = parsed[4];
    m_argList[m_keyList.indexOf("vText6")] = parsed[5];
    m_argList[m_keyList.indexOf("vText5")] = parsed[6];
    m_argList[m_keyList.indexOf("vText4")] = parsed[7];
    m_argList[m_keyList.indexOf("vText3")] = parsed[8];
    m_argList[m_keyList.indexOf("vText2")] = parsed[9];
    m_argList[m_keyList.indexOf("prevref")] = parsed[10];
    m_argList[m_keyList.indexOf("emotionalhistory")] = parsed[12];
    m_argList[m_keyList.indexOf("ttsLocMP3")] = parsed[13];
    m_argList[m_keyList.indexOf("ttsLocTXT")] = parsed[14];
    m_argList[m_keyList.indexOf("ttsLocTXT3")] = parsed[15];
    m_argList[m_keyList.indexOf("ttsText")] = parsed[16];
    m_argList[m_keyList.indexOf("lineRef")] = parsed[17];
    m_argList[m_keyList.indexOf("lineURL")] = parsed[18];
    m_argList[m_keyList.indexOf("linePOST")] = parsed[19];
    m_argList[m_keyList.indexOf("lineChoices")] = parsed[20];
    m_argList[m_keyList.indexOf("lineChoicesAbbrev")] = parsed[21];
    m_argList[m_keyList.indexOf("typingData")] = parsed[22];

    return m_argList[m_keyList.indexOf("ttsText")];
}

QString CleverBot::encode(QList<QString> keyList, QList<QString> argList)
{
    QString text = "";
    QString k;
    QString v;

    for (int i = 0; i < keyList.size(); i++)
    {
        k = keyList[i];
        v = QString(QUrl::toPercentEncoding(argList[i]));
        text += "&" + k + "=" + v;
    }

    return text.mid(1);
}

QString CleverBot::parseRequest(QString req)
{
    req[0] = req[0].toUpper();

    if (req.at(req.size() - 1) == '.' || req.at(req.size() - 1) == '?' || req.at(req.size() - 1) == '!')
        return req;
    else
        req.append('.');

    return req;
}

void CleverBot::emitAfterTimer()
{
    QTextDocument doc;
    doc.setHtml(m_reply);
    m_reply = doc.toPlainText();

    emit hasProcessedData(m_sender, m_reply, m_receiver);
}

int CleverBot::processTimer(QString reply)
{
    int randNumber = (rand() % (m_maxResponseTime - m_minResponseTime + 1) ) + m_minResponseTime;
    return (randNumber + 0.2 * reply.size()) * 1000;
}
