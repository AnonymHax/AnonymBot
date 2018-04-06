#ifndef MOUNTSETMESSAGE_H
#define MOUNTSETMESSAGE_H

#include "Network/Classes/Data/game/mount/MountClientData.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/mount/MountClientData.h"

class MountSetMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MountSetMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MountSetMessage(Reader *param1);
  MountSetMessage();

  QSharedPointer<MountClientData> mountData;
};

#endif // MOUNTSETMESSAGE_H