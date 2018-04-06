#ifndef IDOLSPRESETDELETERESULTMESSAGE_H
#define IDOLSPRESETDELETERESULTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class IdolsPresetDeleteResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IdolsPresetDeleteResultMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IdolsPresetDeleteResultMessage(Reader *param1);
  IdolsPresetDeleteResultMessage();

  uint presetId;
  uint code;
};

#endif // IDOLSPRESETDELETERESULTMESSAGE_H