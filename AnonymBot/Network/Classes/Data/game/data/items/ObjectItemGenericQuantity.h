#ifndef OBJECTITEMGENERICQUANTITY_H
#define OBJECTITEMGENERICQUANTITY_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/Item.h"
#include "Network/Classes/Data/game/data/items/Item.h"

class ObjectItemGenericQuantity : public Item
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectItemGenericQuantity(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectItemGenericQuantity(Reader *param1);
  ObjectItemGenericQuantity();
  bool operator==(const ObjectItemGenericQuantity &compared);

  uint objectGID;
  uint quantity;
};

#endif // OBJECTITEMGENERICQUANTITY_H