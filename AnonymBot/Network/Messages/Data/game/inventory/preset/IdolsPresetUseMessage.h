#ifndef IDOLSPRESETUSEMESSAGE_H
#define IDOLSPRESETUSEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class IdolsPresetUseMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IdolsPresetUseMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IdolsPresetUseMessage(Reader *param1);
  IdolsPresetUseMessage();

  uint presetId;
  bool party;
};

#endif // IDOLSPRESETUSEMESSAGE_H