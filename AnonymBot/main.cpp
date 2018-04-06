#include "Public.h"
#include "GUI/SplashScreen.h"
#include "GUI/MainInterface.h"
#include "System/Tools/IO/D2O/D2OManager.h"
#include "System/Tools/IO/D2P/D2PManager.h"
#include "System/Tools/IO/I18n/I18nFileAccessor.h"
#include "System/Tools/Pathfinding/PathfindingMap.h"
#include "System/ServerInteractions/ServerHandler.h"
#include "Updater/fvupdater.h"

#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <QQuickStyle>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SplashScreen splashScreen(":/Resources/splashScreen.png");
    splashScreen.show();

    qsrand(QDateTime::currentDateTime().toTime_t());

    QApplication::setApplicationVersion(QString::fromUtf8(FV_APP_VERSION));
    QApplication::setOrganizationName("AnonymBot");
    QApplication::setOrganizationDomain("anonymbot.com");

    QString D2O;
    QString D2P;
    QString I18N;
    QFile file(USER_DATA_PATH);

    if (file.open(QFile::ReadOnly))
    {
        QJsonArray array = QJsonDocument::fromBinaryData(file.readAll()).object().value("globalParameters").toArray();

        for (int i = 0; i < array.size(); i++)
        {
            QVariantMap data = array[i].toObject().toVariantMap();

            D2O = data["D2O"].toString();
            D2P = data["D2P"].toString();
            I18N = data["I18N"].toString();
        }

        file.close();
    }

    else
        qDebug()<<"Le fichier"<<USER_DATA_PATH<<"ne peut pas etre ouvert/créé";

    if (!QDir(D2O).exists() || !QDir(D2P).exists() || !QFile::exists(I18N))
    {
        while (!QDir(D2O).exists() || !QDir(D2P).exists() || !QFile::exists(I18N))
        {
#if defined(Q_OS_MAC)
            QFileInfo info(USER_DATA_PATH);
            if (!info.exists())
            {
                qDebug()<<"OS X - Le dossier ressources n'existe pas, on tente de le créer";
                if(!QDir().mkpath(info.dir().path()))
                    qDebug()<<"OS X - Impossible de créer le dossier ressources :"<<USER_DATA_PATH;
            }

            QString path = QFileDialog::getOpenFileName(0, "Selectionnez votre application Dofus", "/Applications");
            D2O = path + "/Contents/Data/Dofus.app/Contents/Resources/data/common";
            D2P = path + "/Contents/Data/Dofus.app/Contents/Resources/content/maps";
            I18N = path + "/Contents/Data/Dofus.app/Contents/Resources/data/i18n/i18n_fr.d2i";
#endif

#if defined(Q_OS_WIN)
            QString path = QFileDialog::getExistingDirectory(0, "Selectionnez le repertoire des ressources de Dofus");
            D2O = path + "/app/data/common";
            D2P = path + "/app/content/maps";
            I18N = path + "/app/data/i18n/i18n_fr.d2i";
#endif
        }

        QJsonArray array;
        QJsonObject data;
        data.insert("D2O", D2O);
        data.insert("D2P", D2P);
        data.insert("I18N", I18N);
        array.append(data);

        QFile file(USER_DATA_PATH);
        if (file.open(QIODevice::ReadWrite))
        {
            QJsonDocument json = QJsonDocument::fromBinaryData(file.readAll());
            file.resize(0);
            QJsonObject object = json.object();
            object.insert("globalParameters", array);
            json.setObject(object);
            file.write(json.toBinaryData());
            file.close();
        }

        else
            qDebug()<<"Le fichier"<<USER_DATA_PATH<<"ne peut pas etre ouvert/créé";
    }

    ServerHandlerSingleton::get()->init();
    D2OManagerSingleton::get()->init(D2O, I18N);
    D2PManagerSingleton::get()->init(D2P);
    PathfindingMap::initialize();
    BotInterface::initialize();

    QPalette p = app.palette();
    p.setColor(QPalette::Base,  QColor(53,53,53));
    p.setColor(QPalette::Link, QColor(178,50,255));
    p.setColor(QPalette::Disabled, QPalette::Base, QColor(80, 80, 80));
    p.setColor(QPalette::Window, QColor(53,53,53));
    p.setColor(QPalette::Disabled, QPalette::Window, QColor(80, 80, 80));
    p.setColor(QPalette::Button, QColor(53,53,53));
    p.setColor(QPalette::Disabled, QPalette::Button, QColor(65, 65, 65));
    p.setColor(QPalette::Highlight, QColor(178,50,255));
    p.setColor(QPalette::HighlightedText, QColor(192,192,192));
    p.setColor(QPalette::Text, QColor(192,192,192));
    p.setColor(QPalette::Disabled, QPalette::Text, QColor(100, 100, 100));
    p.setColor(QPalette::AlternateBase, QColor(60,60,60));
    p.setColor(QPalette::ButtonText, QColor(192,192,192));
    p.setColor(QPalette::Disabled, QPalette::ButtonText, QColor(150, 150, 150));
    p.setColor(QPalette::WindowText, QColor(192,192,192));
    p.setColor(QPalette::Disabled, QPalette::WindowText, QColor(100, 100, 100));
    p.setColor(QPalette::BrightText, QColor(192,192,192));
    p.setColor(QPalette::Disabled, QPalette::BrightText, QColor(100, 100, 85));
    app.setPalette(p);

    QQuickStyle::setStyle("Material");

    app.setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");

    if (QStyleFactory::keys().contains(GUI_THEME))
        app.setStyle(GUI_THEME);
    else
        qDebug() << "La GUI n'a pas pu charger le theme :" << GUI_THEME
                 << ". Ceux disponibles sont :" << QStyleFactory::keys();

    splashScreen.close();

    ProcessEngine p_engine;
    MainInterface *controller = new MainInterface(&p_engine);

    QTime t;
    t.start();

    QQmlApplicationEngine engine;
    QQmlContext *context = engine.rootContext();
    qmlRegisterType<BotInterface>("Utils", 1, 0, "Bot");

#if defined(Q_OS_WIN)
    engine.addImportPath("../QML-Library");
#endif

    context->setContextProperty("controller", controller);
    engine.load(QUrl("qrc:/QML/MainInterface.qml"));
    qDebug()<<"QML - Initialisation - Temps écoulé:"<<t.elapsed()<<"ms";

    return app.exec();
}
