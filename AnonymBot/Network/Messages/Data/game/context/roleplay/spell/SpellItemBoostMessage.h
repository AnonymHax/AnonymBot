#ifndef SPELLITEMBOOSTMESSAGE_H
#define SPELLITEMBOOSTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class SpellItemBoostMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SpellItemBoostMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SpellItemBoostMessage(Reader *param1);
  SpellItemBoostMessage();

  uint statId;
  uint spellId;
  int value;
};

#endif // SPELLITEMBOOSTMESSAGE_H