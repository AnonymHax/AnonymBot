#ifndef OBJECTITEMTOSELL_H
#define OBJECTITEMTOSELL_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/Data/game/data/items/Item.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/Data/game/data/items/Item.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/ClassManager.h"

class ObjectItemToSell : public Item
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectItemToSell(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectItemToSell(Reader *param1);
  ObjectItemToSell();
  bool operator==(const ObjectItemToSell &compared);

  uint objectGID;
  QList<QSharedPointer<ObjectEffect>> effects;
  uint objectUID;
  uint quantity;
  uint objectPrice;
};

#endif // OBJECTITEMTOSELL_H