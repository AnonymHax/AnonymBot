#ifndef DUNGEONPARTYFINDERLISTENREQUESTMESSAGE_H
#define DUNGEONPARTYFINDERLISTENREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DungeonPartyFinderListenRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DungeonPartyFinderListenRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DungeonPartyFinderListenRequestMessage(Reader *param1);
  DungeonPartyFinderListenRequestMessage();

  uint dungeonId;
};

#endif // DUNGEONPARTYFINDERLISTENREQUESTMESSAGE_H