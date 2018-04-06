#ifndef LOCKABLESTATEUPDATEHOUSEDOORMESSAGE_H
#define LOCKABLESTATEUPDATEHOUSEDOORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/lockable/LockableStateUpdateAbstractMessage.h"

class LockableStateUpdateHouseDoorMessage : public LockableStateUpdateAbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_LockableStateUpdateHouseDoorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_LockableStateUpdateHouseDoorMessage(Reader *param1);
  LockableStateUpdateHouseDoorMessage();

  uint houseId;
};

#endif // LOCKABLESTATEUPDATEHOUSEDOORMESSAGE_H