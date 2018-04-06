#ifndef DUNGEONPARTYFINDERROOMCONTENTMESSAGE_H
#define DUNGEONPARTYFINDERROOMCONTENTMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/party/DungeonPartyFinderPlayer.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/party/DungeonPartyFinderPlayer.h"

class DungeonPartyFinderRoomContentMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DungeonPartyFinderRoomContentMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DungeonPartyFinderRoomContentMessage(Reader *param1);
  DungeonPartyFinderRoomContentMessage();

  uint dungeonId;
  QList<DungeonPartyFinderPlayer> players;
};

#endif // DUNGEONPARTYFINDERROOMCONTENTMESSAGE_H