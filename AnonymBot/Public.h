#ifndef PUBLIC_H
#define PUBLIC_H

// Fichier contenant toute les inclusions

#include <iostream>
#include <zlib.h>

#include <QSslSocket>
#include <QMainWindow>
#include <QDebug>
#include <QTcpSocket>
#include <QApplication>
#include <QTcpServer>
#include <QTimer>
#include <QDateTime>
#include <QtEndian>
#include <QNetworkProxy>
#include <QStringListModel>
#include <QDialog>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
#include <QElapsedTimer>
#include <QtCore/qmath.h>
#include <QSplashScreen>
#include <QMovie>
#include <QLabel>
#include <QBuffer>
#include <QDirIterator>
#include <QElapsedTimer>
#include <QStyleFactory>
#include <QThread>
#include <QJsonDocument>
#include <QJsonArray>
#include <QMutex>
#include <QSharedPointer>

// Main
#define GUI_THEME "Fusion"

// Global
#define INVALID -1

//ZLib
QByteArray gUncompress(const QByteArray &data);

// User's data path
#define USER_DATA_PATH getRessourcesPath()+"/data.anm"

// Reader - Writer
struct SpecialInt
{
    uint low = 0;
    uint high = 0;
};

int toInt(QString string);
uint toUInt(QString string);
float toFloat(QString string);

QString dateToString(const double &milliseconds);

QString getRessourcesPath();

QString toHtml(const QString &plainText);

#endif // PUBLIC_H
