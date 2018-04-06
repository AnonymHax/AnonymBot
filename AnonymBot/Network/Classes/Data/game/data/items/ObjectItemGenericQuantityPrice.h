#ifndef OBJECTITEMGENERICQUANTITYPRICE_H
#define OBJECTITEMGENERICQUANTITYPRICE_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/ObjectItemGenericQuantity.h"

class ObjectItemGenericQuantityPrice : public ObjectItemGenericQuantity
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectItemGenericQuantityPrice(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectItemGenericQuantityPrice(Reader *param1);
  ObjectItemGenericQuantityPrice();
  bool operator==(const ObjectItemGenericQuantityPrice &compared);

  uint price;
};

#endif // OBJECTITEMGENERICQUANTITYPRICE_H