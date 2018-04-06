#ifndef IDOLSPRESETDELETEMESSAGE_H
#define IDOLSPRESETDELETEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class IdolsPresetDeleteMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IdolsPresetDeleteMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IdolsPresetDeleteMessage(Reader *param1);
  IdolsPresetDeleteMessage();

  uint presetId;
};

#endif // IDOLSPRESETDELETEMESSAGE_H