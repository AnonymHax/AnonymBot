#ifndef OBJECTITEMTOSELLINNPCSHOP_H
#define OBJECTITEMTOSELLINNPCSHOP_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/ObjectItemMinimalInformation.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"

class ObjectItemToSellInNpcShop : public ObjectItemMinimalInformation
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectItemToSellInNpcShop(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectItemToSellInNpcShop(Reader *param1);
  ObjectItemToSellInNpcShop();
  bool operator==(const ObjectItemToSellInNpcShop &compared);

  uint objectPrice;
  QString buyCriterion;
};

#endif // OBJECTITEMTOSELLINNPCSHOP_H