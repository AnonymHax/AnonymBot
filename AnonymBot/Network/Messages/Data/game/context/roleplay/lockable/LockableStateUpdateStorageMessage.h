#ifndef LOCKABLESTATEUPDATESTORAGEMESSAGE_H
#define LOCKABLESTATEUPDATESTORAGEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/lockable/LockableStateUpdateAbstractMessage.h"

class LockableStateUpdateStorageMessage : public LockableStateUpdateAbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_LockableStateUpdateStorageMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_LockableStateUpdateStorageMessage(Reader *param1);
  LockableStateUpdateStorageMessage();

  int mapId;
  uint elementId;
};

#endif // LOCKABLESTATEUPDATESTORAGEMESSAGE_H