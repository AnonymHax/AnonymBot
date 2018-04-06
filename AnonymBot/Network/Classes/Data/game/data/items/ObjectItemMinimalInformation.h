#ifndef OBJECTITEMMINIMALINFORMATION_H
#define OBJECTITEMMINIMALINFORMATION_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/Data/game/data/items/Item.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/ClassManager.h"

class ObjectItemMinimalInformation : public Item
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectItemMinimalInformation(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectItemMinimalInformation(Reader *param1);
  ObjectItemMinimalInformation();
  bool operator==(const ObjectItemMinimalInformation &compared);

  uint objectGID;
  QList<QSharedPointer<ObjectEffect>> effects;
};

#endif // OBJECTITEMMINIMALINFORMATION_H