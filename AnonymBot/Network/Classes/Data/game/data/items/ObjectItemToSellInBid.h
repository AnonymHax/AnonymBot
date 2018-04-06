#ifndef OBJECTITEMTOSELLINBID_H
#define OBJECTITEMTOSELLINBID_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/ObjectItemToSell.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"

class ObjectItemToSellInBid : public ObjectItemToSell
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectItemToSellInBid(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectItemToSellInBid(Reader *param1);
  ObjectItemToSellInBid();
  bool operator==(const ObjectItemToSellInBid &compared);

  uint unsoldDelay;
};

#endif // OBJECTITEMTOSELLINBID_H