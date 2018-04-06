#include "TiphonEntityLook.h"

TiphonEntityLook::TiphonEntityLook()
{
    m_scaleX = 1;
    m_scaleY = 1;
    m_defaultSkin = -1;
}

TiphonEntityLook::~TiphonEntityLook()
{
}

QMap<uint, TiphonEntityLook> TiphonEntityLook::getSubEntitiesFromCategory(uint category)
{
    return m_subEntities[category];
}

QMap< uint, QMap<uint, TiphonEntityLook> > TiphonEntityLook::getSubEntities()
{
    return m_subEntities;
}

TiphonEntityLook TiphonEntityLook::getSubEntity(uint category, uint index)
{
    return m_subEntities[category][index];
}

QList<uint> TiphonEntityLook::getSkins(bool keepDefault)
{
    return m_skins;
}

DefaultableColor TiphonEntityLook::getColor(uint index)
{
    if (!m_colors[index])
    {
        DefaultableColor c;
        c.setIsDefault(true);
        return c;
    }

    return DefaultableColor(m_colors[index]);
}

QMap<uint, uint> TiphonEntityLook::getColors()
{
    return m_colors;
}

bool TiphonEntityLook::hasColor(uint index)
{
    return !!m_colors[index];
}


int TiphonEntityLook::getDefaultSkin()
{
    return m_defaultSkin;
}

uint TiphonEntityLook::getFirstSkin()
{
    if (m_skins.isEmpty())
        return 0;
    else if (!(m_defaultSkin == -1) && (m_skins.size() > 1))
        return m_skins[1];

    return m_skins[0];
}

double TiphonEntityLook::getScaleX()
{
    return m_scaleX;
}

double TiphonEntityLook::getScaleY()
{
    return m_scaleY;
}

uint TiphonEntityLook::getBone()
{
    return m_bone;
}

void TiphonEntityLook::addSubEntity(uint category, uint index, TiphonEntityLook subEntity)
{
    m_subEntities[category][index] = subEntity;
}

void TiphonEntityLook::removeSubEntity(uint category, uint index)
{
    m_subEntities[category].remove(index);
}

void TiphonEntityLook::addSkin(uint skin, bool firstPos)
{
    if (firstPos)
        m_skins.prepend(skin);
    else
        m_skins.append(skin);
}

void TiphonEntityLook::setColor(uint index, uint color)
{
    if (color == 0)
        m_colors[index] = 1;
    else
        m_colors[index] = color;
}

void TiphonEntityLook::setScales(double x, double y)
{
    if ((m_scaleX == x) && (m_scaleY == y))
        return;

    m_scaleX = x;
    m_scaleY = y;
}

void TiphonEntityLook::resetColor(uint index)
{
    if (!m_colors[index])
        return;

    m_colors.remove(index);
}

void TiphonEntityLook::setDefaultSkin(int id)
{
    if (m_skins.size() && m_skins.first() == id)
        return;

    m_defaultSkin = id;
    if (m_skins.isEmpty())
        m_skins.prepend(id);
}

void TiphonEntityLook::removeSkin(uint skin)
{
    if (m_skins.isEmpty() || !m_skins.contains(skin))
        return;

    m_skins.removeAt(m_skins.indexOf(skin));
}

void TiphonEntityLook::setScaleX(double val)
{
    m_scaleX = val;
}

void TiphonEntityLook::setScaleY(double val)
{
    m_scaleY = val;
}

void TiphonEntityLook::setBone(uint bone)
{
    if (m_bone == bone)
        return;

    m_bone = bone;
}

void TiphonEntityLook::resetSubEntities()
{
    m_subEntities.clear();
}

void TiphonEntityLook::resetColors()
{
    m_colors.clear();
}

void TiphonEntityLook::resetSkins()
{
    m_skins.clear();
}
