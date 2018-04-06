#ifndef SUBENTITY_H
#define SUBENTITY_H

#include "Network/Classes/AbstractClass.h"

class EntityLook;

class SubEntity : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SubEntity(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SubEntity(Reader *param1);
  SubEntity();
  bool operator==(const SubEntity &compared);

  uint bindingPointCategory;
  uint bindingPointIndex;
  QSharedPointer<EntityLook> subEntityLook;
};

#endif // SUBENTITY_H