#include <QDebug>
#include <QtCore>
#include "Controller.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Controller controller;

    return app.exec();
}
