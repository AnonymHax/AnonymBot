#ifndef SERVERSLISTMESSAGE_H
#define SERVERSLISTMESSAGE_H

#include "Network/Classes/Data/connection/GameServerInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/connection/GameServerInformations.h"

class ServersListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ServersListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ServersListMessage(Reader *param1);
  ServersListMessage();

  QList<GameServerInformations> servers;
  uint alreadyConnectedToServerId;
  bool canCreateNewCharacter;
};

#endif // SERVERSLISTMESSAGE_H