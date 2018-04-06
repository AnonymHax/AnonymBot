#ifndef IDOLSPRESETSAVERESULTMESSAGE_H
#define IDOLSPRESETSAVERESULTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class IdolsPresetSaveResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IdolsPresetSaveResultMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IdolsPresetSaveResultMessage(Reader *param1);
  IdolsPresetSaveResultMessage();

  uint presetId;
  uint code;
};

#endif // IDOLSPRESETSAVERESULTMESSAGE_H