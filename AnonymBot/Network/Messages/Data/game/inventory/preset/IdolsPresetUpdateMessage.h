#ifndef IDOLSPRESETUPDATEMESSAGE_H
#define IDOLSPRESETUPDATEMESSAGE_H

#include "Network/Classes/Data/game/inventory/preset/IdolsPreset.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/inventory/preset/IdolsPreset.h"

class IdolsPresetUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IdolsPresetUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IdolsPresetUpdateMessage(Reader *param1);
  IdolsPresetUpdateMessage();

  IdolsPreset idolsPreset;
};

#endif // IDOLSPRESETUPDATEMESSAGE_H