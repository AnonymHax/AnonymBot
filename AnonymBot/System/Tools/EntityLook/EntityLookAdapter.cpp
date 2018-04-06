#include "EntityLookAdapter.h"

EntityLookAdapter::EntityLookAdapter()
{
}

EntityLookAdapter::~EntityLookAdapter()
{
}

TiphonEntityLook EntityLookAdapter::fromNetwork(QSharedPointer<EntityLook> el)
{
    TiphonEntityLook t;
    t.setBone(el->bonesId);
    for (int i = 0; i < el->skins.size(); i++)
        t.addSkin(el->skins[i]);

    for (int i = 0; i < el->indexedColors.size(); i++)
    {
        uint index = ((el->indexedColors[i] >> 24) & 0xFF);
        uint color = (el->indexedColors[i] & 0xFFFFFF);
        t.setColor(index, color);
    }

    if (el->scales.size() == 1)
        t.setScales((el->scales[0] / 100.0), (el->scales[0] / 100.0));
    else if (el->scales.size() == 2)
        t.setScales((el->scales[0] / 100.0), (el->scales[1] / 100.0));
    else
        qDebug() << "EntityLookAdapter: error scales size unknown:" << el->scales.size();

    foreach (QSharedPointer<SubEntity> se, el->subentities)
        t.addSubEntity(se->bindingPointCategory, se->bindingPointIndex, EntityLookAdapter::fromNetwork(se->subEntityLook));

    return t;
}
