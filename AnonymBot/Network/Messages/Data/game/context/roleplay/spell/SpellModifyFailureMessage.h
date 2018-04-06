#ifndef SPELLMODIFYFAILUREMESSAGE_H
#define SPELLMODIFYFAILUREMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class SpellModifyFailureMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SpellModifyFailureMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SpellModifyFailureMessage(Reader *param1);
  SpellModifyFailureMessage();
};

#endif // SPELLMODIFYFAILUREMESSAGE_H