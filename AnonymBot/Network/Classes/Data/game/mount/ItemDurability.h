#ifndef ITEMDURABILITY_H
#define ITEMDURABILITY_H

#include "Network/Classes/AbstractClass.h"

class ItemDurability : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ItemDurability(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ItemDurability(Reader *param1);
  ItemDurability();
  bool operator==(const ItemDurability &compared);

  int durability;
  int durabilityMax;
};

#endif // ITEMDURABILITY_H