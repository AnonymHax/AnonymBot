#ifndef SPELLVARIANTACTIVATIONREQUESTMESSAGE_H
#define SPELLVARIANTACTIVATIONREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class SpellVariantActivationRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SpellVariantActivationRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SpellVariantActivationRequestMessage(Reader *param1);
  SpellVariantActivationRequestMessage();

  uint spellId;
};

#endif // SPELLVARIANTACTIVATIONREQUESTMESSAGE_H