#ifndef ENTITYLOOK_H
#define ENTITYLOOK_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/look/SubEntity.h"

class EntityLook : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_EntityLook(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_EntityLook(Reader *param1);
  EntityLook();
  bool operator==(const EntityLook &compared);

  uint bonesId;
  QList<uint> skins;
  QList<int> indexedColors;
  QList<int> scales;
  QList<QSharedPointer<SubEntity>> subentities;
};

#endif // ENTITYLOOK_H