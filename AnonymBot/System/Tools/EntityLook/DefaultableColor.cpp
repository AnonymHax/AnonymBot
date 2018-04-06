#include "DefaultableColor.h"

DefaultableColor::DefaultableColor(uint color)
{
    parseColor(color);
    m_default = false;
}

DefaultableColor::~DefaultableColor()
{
}

void DefaultableColor::parseColor(uint color)
{
    m_red = ((color & 0xFF0000) >> 16);
    m_green = ((color & 0xFF00) >> 8);
    m_blue = (color & 0xFF);
}

bool DefaultableColor::isDefault()
{
    return m_default;
}

uint DefaultableColor::color()
{
    return ((((m_red & 0xFF) << 16) | ((m_green & 0xFF) << 8)) | (m_blue & 0xFF));
}

uint DefaultableColor::green()
{
    return m_green;
}

uint DefaultableColor::blue()
{
    return m_blue;
}

uint DefaultableColor::red()
{
    return m_red;
}

void DefaultableColor::setColor(uint color)
{
    parseColor(color);
}

void DefaultableColor::setIsDefault(bool d)
{
    m_default = d;
}
