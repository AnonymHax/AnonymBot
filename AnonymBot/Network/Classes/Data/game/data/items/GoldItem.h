#ifndef GOLDITEM_H
#define GOLDITEM_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/Item.h"

class GoldItem : public Item
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GoldItem(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GoldItem(Reader *param1);
  GoldItem();
  bool operator==(const GoldItem &compared);

  uint sum;
};

#endif // GOLDITEM_H