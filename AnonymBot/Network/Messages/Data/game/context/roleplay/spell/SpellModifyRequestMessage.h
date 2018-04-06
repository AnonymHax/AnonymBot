#ifndef SPELLMODIFYREQUESTMESSAGE_H
#define SPELLMODIFYREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class SpellModifyRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SpellModifyRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SpellModifyRequestMessage(Reader *param1);
  SpellModifyRequestMessage();

  uint spellId;
  int spellLevel;
};

#endif // SPELLMODIFYREQUESTMESSAGE_H