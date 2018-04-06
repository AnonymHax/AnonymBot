#include "Public.h"

#include "string"
#include <iostream>
#include <math.h>
#include <stdint.h>
#include <sstream>
#include <limits>
#include <cassert>

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
