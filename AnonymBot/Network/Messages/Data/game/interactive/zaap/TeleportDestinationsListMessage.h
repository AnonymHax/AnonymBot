#ifndef TELEPORTDESTINATIONSLISTMESSAGE_H
#define TELEPORTDESTINATIONSLISTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TeleportDestinationsListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TeleportDestinationsListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TeleportDestinationsListMessage(Reader *param1);
  TeleportDestinationsListMessage();

  uint teleporterType;
  QList<uint> mapIds;
  QList<uint> subAreaIds;
  QList<uint> costs;
  QList<uint> destTeleporterType;
};

#endif // TELEPORTDESTINATIONSLISTMESSAGE_H