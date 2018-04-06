#ifndef OBJECTITEMQUANTITY_H
#define OBJECTITEMQUANTITY_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/Item.h"

class ObjectItemQuantity : public Item
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectItemQuantity(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectItemQuantity(Reader *param1);
  ObjectItemQuantity();
  bool operator==(const ObjectItemQuantity &compared);

  uint objectUID;
  uint quantity;
};

#endif // OBJECTITEMQUANTITY_H