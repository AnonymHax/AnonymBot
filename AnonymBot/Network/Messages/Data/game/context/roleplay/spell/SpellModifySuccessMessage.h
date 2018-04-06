#ifndef SPELLMODIFYSUCCESSMESSAGE_H
#define SPELLMODIFYSUCCESSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class SpellModifySuccessMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SpellModifySuccessMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SpellModifySuccessMessage(Reader *param1);
  SpellModifySuccessMessage();

  int spellId;
  int spellLevel;
};

#endif // SPELLMODIFYSUCCESSMESSAGE_H