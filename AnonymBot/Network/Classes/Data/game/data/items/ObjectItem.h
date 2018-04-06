#ifndef OBJECTITEM_H
#define OBJECTITEM_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/Data/game/data/items/Item.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/ClassManager.h"

class ObjectItem : public Item
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectItem(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectItem(Reader *param1);
  ObjectItem();
  bool operator==(const ObjectItem &compared);

  uint position;
  uint objectGID;
  QList<QSharedPointer<ObjectEffect>> effects;
  uint objectUID;
  uint quantity;
};

#endif // OBJECTITEM_H