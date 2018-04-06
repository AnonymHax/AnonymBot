#ifndef ITEM_H
#define ITEM_H

#include "Network/Classes/AbstractClass.h"

class Item : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_Item(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_Item(Reader *param1);
  Item();
  bool operator==(const Item &compared);
};

#endif // ITEM_H