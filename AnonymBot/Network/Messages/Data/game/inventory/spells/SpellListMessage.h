#ifndef SPELLLISTMESSAGE_H
#define SPELLLISTMESSAGE_H

#include "Network/Classes/Data/game/data/items/SpellItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/SpellItem.h"

class SpellListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SpellListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SpellListMessage(Reader *param1);
  SpellListMessage();

  bool spellPrevisualization;
  QList<SpellItem> spells;
};

#endif // SPELLLISTMESSAGE_H