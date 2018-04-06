#ifndef OBJECTITEMNOTINCONTAINER_H
#define OBJECTITEMNOTINCONTAINER_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/Data/game/data/items/Item.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/ClassManager.h"

class ObjectItemNotInContainer : public Item
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectItemNotInContainer(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectItemNotInContainer(Reader *param1);
  ObjectItemNotInContainer();
  bool operator==(const ObjectItemNotInContainer &compared);

  uint objectGID;
  QList<QSharedPointer<ObjectEffect>> effects;
  uint objectUID;
  uint quantity;
};

#endif // OBJECTITEMNOTINCONTAINER_H