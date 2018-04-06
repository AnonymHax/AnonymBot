#ifndef ZAAPLISTMESSAGE_H
#define ZAAPLISTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/interactive/zaap/TeleportDestinationsListMessage.h"

class ZaapListMessage : public TeleportDestinationsListMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ZaapListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ZaapListMessage(Reader *param1);
  ZaapListMessage();

  uint spawnMapId;
};

#endif // ZAAPLISTMESSAGE_H