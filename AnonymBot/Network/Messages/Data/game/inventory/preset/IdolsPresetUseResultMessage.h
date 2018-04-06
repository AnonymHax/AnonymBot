#ifndef IDOLSPRESETUSERESULTMESSAGE_H
#define IDOLSPRESETUSERESULTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class IdolsPresetUseResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IdolsPresetUseResultMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IdolsPresetUseResultMessage(Reader *param1);
  IdolsPresetUseResultMessage();

  uint presetId;
  uint code;
  QList<uint> missingIdols;
};

#endif // IDOLSPRESETUSERESULTMESSAGE_H