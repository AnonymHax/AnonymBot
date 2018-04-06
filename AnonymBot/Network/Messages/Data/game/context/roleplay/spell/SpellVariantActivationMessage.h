#ifndef SPELLVARIANTACTIVATIONMESSAGE_H
#define SPELLVARIANTACTIVATIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class SpellVariantActivationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SpellVariantActivationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SpellVariantActivationMessage(Reader *param1);
  SpellVariantActivationMessage();

  bool result;
  uint activatedSpellId;
  uint deactivatedSpellId;
};

#endif // SPELLVARIANTACTIVATIONMESSAGE_H