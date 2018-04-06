#include "SplashScreen.h"

SplashScreen::SplashScreen(const QString &filePath)
{
    m_animation.setFileName(filePath);
    QSize size;
    size.setHeight(400);
    size.setWidth(800);
    m_animation.setScaledSize(size);
    m_animation.start();
    setMovie(&m_animation);
    //setWindowModality(Qt::WindowModal);
    setWindowFlags(Qt::SplashScreen);
}
