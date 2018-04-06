#include "Public.h"

#include "string"
#include <iostream>
#include <math.h>
#include <stdint.h>
#include <sstream>
#include <limits>
#include <cassert>

QByteArray gUncompress(const QByteArray &data)
{
    if (data.size() <= 4)
    {
        qWarning("gUncompress: Input data is truncated");
        return QByteArray();
    }

    QByteArray result;

    int ret;
    z_stream strm;
    static const int CHUNK_SIZE = 1024;
    char out[CHUNK_SIZE];

    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    strm.avail_in = data.size();
    strm.next_in = (Bytef*)(data.data());

    ret = inflateInit2(&strm, 15 +  32);
    if (ret != Z_OK)
        return QByteArray();

    do {
        strm.avail_out = CHUNK_SIZE;
        strm.next_out = (Bytef*)(out);

        ret = inflate(&strm, Z_NO_FLUSH);
        Q_ASSERT(ret != Z_STREAM_ERROR);

        switch (ret) {
        case Z_NEED_DICT:
            ret = Z_DATA_ERROR;
        case Z_DATA_ERROR:
        case Z_MEM_ERROR:
            (void)inflateEnd(&strm);
            return QByteArray();
        }

        result.append(out, CHUNK_SIZE - strm.avail_out);
    } while (strm.avail_out == 0);

    inflateEnd(&strm);
    return result;
}

//Convertisseurs chiffres/lettres
int toInt(QString string)
{
    std::string stdString = string.toStdString();
    std::istringstream number (stdString);
    int result;

    number >> result;

    return result;
}

uint toUInt(QString string)
{
    std::string stdString = string.toStdString();
    std::istringstream number (stdString);
    uint result;

    number >> result;

    return result;
}

float toFloat(QString string)
{
    std::string stdString = string.toStdString();
    std::istringstream number (stdString);
    float result;

    number >> result;

    return result;
}

QString dateToString(const double &milliseconds)
{
    uint seconds = milliseconds/1000;
    QDateTime toDateTime = QDateTime::fromTime_t(seconds);
    QString dateToString;
    dateToString += QString::number(toDateTime.date().day());
    dateToString += " ";

    switch (toDateTime.date().month())
    {
    default:
        throw "Date inconnue";
        break;

    case 1:
        dateToString += "Janvier";
        break;

    case 2:
        dateToString += "Fevrier";
        break;

    case 3:
        dateToString += "Mars";
        break;

    case 4:
        dateToString += "Avril";
        break;

    case 5:
        dateToString += "Mai";
        break;

    case 6:
        dateToString += "Juin";
        break;

    case 7:
        dateToString += "Juillet";
        break;

    case 8:
        dateToString += "Aout";
        break;

    case 9:
        dateToString += "Septembre";
        break;

    case 10:
        dateToString += "Octobre";
        break;

    case 11:
        dateToString += "Novembre";
        break;

    case 12:
        dateToString += "Decembre";
        break;
    }

    dateToString += " ";
    dateToString += QString::number(toDateTime.date().year());
    dateToString += " - ";
    if (toDateTime.time().hour() < 10)
        dateToString += "0";
    dateToString += QString::number(toDateTime.time().hour());
    dateToString += "h";
    if (toDateTime.time().minute() < 10)
        dateToString += "0";
    dateToString += QString::number(toDateTime.time().minute());

    return dateToString;
}

QString getRessourcesPath()
{
    QString path = QCoreApplication::applicationDirPath();

#ifdef __APPLE__
    path.remove(path.size()-6, 7);
    path+="/Resources";
#endif

    return path;
}

QString toHtml(const QString &plainText)
{
    QString htmlText;
    int charactersAdded= 0;

    for(int i = 0; i < plainText.size(); i++)
    {
        if (plainText[i] == '\n')
        {
            htmlText.insert(i+charactersAdded, "<br/>");
            charactersAdded += 4;
        }

        else if (plainText[i] == '\t')
            htmlText.insert(i+charactersAdded, "    ");

        else
            htmlText+=plainText[i];
    }

    return htmlText;
}
