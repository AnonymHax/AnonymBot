#ifndef PADDOCKITEM_H
#define PADDOCKITEM_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/mount/ItemDurability.h"
#include "Network/Classes/Data/game/context/roleplay/ObjectItemInRolePlay.h"
#include "Network/Classes/Data/game/context/roleplay/ObjectItemInRolePlay.h"
#include "Network/Classes/Data/game/mount/ItemDurability.h"

class PaddockItem : public ObjectItemInRolePlay
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PaddockItem(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PaddockItem(Reader *param1);
  PaddockItem();
  bool operator==(const PaddockItem &compared);

  ItemDurability durability;
};

#endif // PADDOCKITEM_H