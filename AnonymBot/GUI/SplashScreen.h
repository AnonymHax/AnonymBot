#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include "Public.h"

class SplashScreen : public QLabel
{
public:

    SplashScreen(const QString &filePath);

private:

    QMovie m_animation;
};

#endif // SPLASHSCREEN_H
