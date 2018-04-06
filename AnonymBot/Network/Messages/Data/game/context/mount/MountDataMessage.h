#ifndef MOUNTDATAMESSAGE_H
#define MOUNTDATAMESSAGE_H

#include "Network/Classes/Data/game/mount/MountClientData.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/mount/MountClientData.h"

class MountDataMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MountDataMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MountDataMessage(Reader *param1);
  MountDataMessage();

  QSharedPointer<MountClientData> mountData;
};

#endif // MOUNTDATAMESSAGE_H