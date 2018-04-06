#ifndef INDEXEDENTITYLOOK_H
#define INDEXEDENTITYLOOK_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/look/EntityLook.h"

class IndexedEntityLook : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IndexedEntityLook(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IndexedEntityLook(Reader *param1);
  IndexedEntityLook();
  bool operator==(const IndexedEntityLook &compared);

  QSharedPointer<EntityLook> look;
  uint index;
};

#endif // INDEXEDENTITYLOOK_H