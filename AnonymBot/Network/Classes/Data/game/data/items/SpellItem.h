#ifndef SPELLITEM_H
#define SPELLITEM_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/Item.h"

class SpellItem : public Item
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SpellItem(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SpellItem(Reader *param1);
  SpellItem();
  bool operator==(const SpellItem &compared);

  int spellId;
  int spellLevel;
};

#endif // SPELLITEM_H