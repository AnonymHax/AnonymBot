#ifndef PUBLIC_H
#define PUBLIC_H

// Fichier contenant toute les inclusions

#include <iostream>
#include <zlib.h>

#include <QCryptographicHash>
#include <QDebug>
#include <QSslSocket>
#include <QQueue>
#include <QTcpServer>
#include <QTimer>
#include <QDateTime>
#include <QtEndian>
#include <QNetworkProxy>
#include <QStringListModel>
#include <QTextStream>
#include <QFile>
#include <QElapsedTimer>
#include <QtCore/qmath.h>
#include <QMovie>
#include <QBuffer>
#include <QDirIterator>
#include <QElapsedTimer>
#include <QThread>

// Global
#define INVALID -1

int toInt(QString string);
uint toUInt(QString string);
float toFloat(QString string);

QString dateToString(const double &milliseconds);

// Reader - Writer
struct SpecialInt
{
    uint low = 0;
    uint high = 0;
};

#endif // PUBLIC_H
