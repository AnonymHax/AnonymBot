#include "EntityLookParser.h"

EntityLookParser::EntityLookParser()
{
}

EntityLookParser::~EntityLookParser()
{
}

QString EntityLookParser::getUrl(QSharedPointer<EntityLook> entity, EntityRendererType t, EntityRendererOrientation o)
{
    QString url = "http://staticns.ankama.com/dofus/renderer/look/";
    TiphonEntityLook tiphon = EntityLookAdapter::fromNetwork(entity);
    QString entityLook = EntityLookParser::toString(tiphon);
    url += entityLook.toLatin1().toHex();

    if (t == EntityRendererType::FULL)
        url += QString("/full/") + QString::number((int)o) + QString("/768_768-10.png");
    else if (t == EntityRendererType::FACE)
        url += QString("/face/") + QString::number((int)o) + QString("/96_96-0.png");
    else
        qDebug() << "EntityLookParser: error unknown orientation:" << (int)o;

    return url;
}

QString EntityLookParser::toString(TiphonEntityLook el)
{
    QString out = "{";
    QList<uint> skins = el.getSkins(true);
    out += (QString::number(el.getBone()) + QString("|"));

    if (skins.size())
    {
        int i = 0;
        bool firstSkin = true;
        foreach (uint skin, skins)
        {
            if (!(i++ == 0 && el.getDefaultSkin() != -1))
            {
                if (firstSkin)
                    firstSkin = false;
                else
                    out += QString(',');

                out += QString::number(skin);
            }
        }
    }

    out += QString("|");
    if (el.getColors().size())
    {
        bool firstColor = true;
        foreach (int colorIndex, el.getColors().keys())
        {
            if (firstColor)
                firstColor = false;
            else
                out = out + QString(",");


            out += QString::number(colorIndex) + QString("=") + QString::number(el.getColors()[colorIndex]);
        }
    }

    out += QString("|");
    double scaleX = el.getScaleX();
    double scaleY = el.getScaleY();
    if (scaleX != 1 || scaleY != 1)
    {
        out += QString::number(round(scaleX * 100));
        if (scaleX != scaleY)
            out += QString(",") + QString::number(round(scaleY * 100));
    }

    out += QString("|");
    if (el.getSubEntities().size())
    {
        bool firstSubEntity = true;
        foreach (uint category, el.getSubEntities().keys())
        {
            foreach (uint index, el.getSubEntities()[category].keys())
            {
                TiphonEntityLook tl = el.getSubEntities()[category][index];
                if (firstSubEntity)
                    firstSubEntity = false;
                else
                    out += QString(",");

                out += QString::number(category) + QString("@") + QString::number(index) + QString("=") + EntityLookParser::toString(tl);
            }
        }
    }

    while (out.at(out.size() - 1) == QChar('|'))
        out.chop(1);

    return out + QString("}");
}
