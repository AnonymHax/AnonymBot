#ifndef TIPHONENTITYLOOK_H
#define TIPHONENTITYLOOK_H

#include "DefaultableColor.h"
#include "Public.h"

class TiphonEntityLook
{
public:
    TiphonEntityLook();
    ~TiphonEntityLook();

    //getters
    QMap<uint, TiphonEntityLook> getSubEntitiesFromCategory(uint category);
    QMap< uint, QMap<uint, TiphonEntityLook> > getSubEntities();
    TiphonEntityLook getSubEntity(uint category, uint index);
    QList<uint> getSkins(bool keepDefault = true);
    DefaultableColor getColor(uint index);
    QMap<uint, uint> getColors();
    bool hasColor(uint index);
    int getDefaultSkin();
    uint getFirstSkin();
    double getScaleX();
    double getScaleY();
    uint getBone();

    //setters
    void addSubEntity(uint category, uint index, TiphonEntityLook subEntity);
    void removeSubEntity(uint category, uint index = 0);
    void addSkin(uint skin, bool firstPos=false);
    void setColor(uint index, uint color);
    void setScales(double x, double y);
    void resetColor(uint index);
    void setDefaultSkin(int id);
    void removeSkin(uint skin);
    void setScaleX(double val);
    void setScaleY(double val);
    void setBone(uint bone);
    void resetSubEntities();
    void resetColors();
    void resetSkins();

private:
    QMap< uint, QMap<uint, TiphonEntityLook> > m_subEntities;
    QMap<uint, uint> m_colors;
    QList<uint> m_skins;
    int m_defaultSkin;
    double m_scaleX;
    double m_scaleY;
    uint m_bone;
};

#endif // TIPHONENTITYLOOK_H
