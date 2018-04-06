#ifndef ENTITYLOOKPARSER_H
#define ENTITYLOOKPARSER_H

#include "Public.h"
#include "TiphonEntityLook.h"
#include "EntityLookAdapter.h"
#include "System/Engines/DataHandler.h"
#include "Network/Classes/Data/game/look/EntityLook.h"

class EntityLookParser
{
public:
    EntityLookParser();
    ~EntityLookParser();

    static QString getUrl(QSharedPointer<EntityLook> entity, EntityRendererType t, EntityRendererOrientation o);
    static QString toString(TiphonEntityLook el);
};

#endif // ENTITYLOOKPARSER_H
