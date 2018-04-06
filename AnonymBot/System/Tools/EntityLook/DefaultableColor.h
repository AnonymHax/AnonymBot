#ifndef DEFAULTABLECOLOR_H
#define DEFAULTABLECOLOR_H

#include "Public.h"

class DefaultableColor
{
public:
    DefaultableColor(uint color = 0);
    ~DefaultableColor();

    //getters
    bool isDefault();
    uint color();
    uint green();
    uint blue();
    uint red();

    //setters
    void setColor(uint color);
    void setIsDefault(bool d);

private:
    void parseColor(uint color);

    uint m_red;
    uint m_blue;
    uint m_green;
    bool m_default;
};

#endif // DEFAULTABLECOLOR_H
