#ifndef IDOLSPRESETSAVEMESSAGE_H
#define IDOLSPRESETSAVEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class IdolsPresetSaveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IdolsPresetSaveMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IdolsPresetSaveMessage(Reader *param1);
  IdolsPresetSaveMessage();

  uint presetId;
  uint symbolId;
};

#endif // IDOLSPRESETSAVEMESSAGE_H