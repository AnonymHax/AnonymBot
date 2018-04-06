#ifndef OBJECTITEMTOSELLINHUMANVENDORSHOP_H
#define OBJECTITEMTOSELLINHUMANVENDORSHOP_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/Data/game/data/items/Item.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/ClassManager.h"

class ObjectItemToSellInHumanVendorShop : public Item
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectItemToSellInHumanVendorShop(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectItemToSellInHumanVendorShop(Reader *param1);
  ObjectItemToSellInHumanVendorShop();
  bool operator==(const ObjectItemToSellInHumanVendorShop &compared);

  uint objectGID;
  QList<QSharedPointer<ObjectEffect>> effects;
  uint objectUID;
  uint quantity;
  uint objectPrice;
  uint publicPrice;
};

#endif // OBJECTITEMTOSELLINHUMANVENDORSHOP_H