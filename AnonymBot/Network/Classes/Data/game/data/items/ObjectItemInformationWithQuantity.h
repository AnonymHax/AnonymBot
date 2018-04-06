#ifndef OBJECTITEMINFORMATIONWITHQUANTITY_H
#define OBJECTITEMINFORMATIONWITHQUANTITY_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/ObjectItemMinimalInformation.h"
#include "Network/Classes/Data/game/data/items/ObjectItemMinimalInformation.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"

class ObjectItemInformationWithQuantity : public ObjectItemMinimalInformation
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectItemInformationWithQuantity(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectItemInformationWithQuantity(Reader *param1);
  ObjectItemInformationWithQuantity();
  bool operator==(const ObjectItemInformationWithQuantity &compared);

  uint quantity;
};

#endif // OBJECTITEMINFORMATIONWITHQUANTITY_H