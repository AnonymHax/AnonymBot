#ifndef DUNGEONPARTYFINDERROOMCONTENTUPDATEMESSAGE_H
#define DUNGEONPARTYFINDERROOMCONTENTUPDATEMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/party/DungeonPartyFinderPlayer.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/party/DungeonPartyFinderPlayer.h"

class DungeonPartyFinderRoomContentUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DungeonPartyFinderRoomContentUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DungeonPartyFinderRoomContentUpdateMessage(Reader *param1);
  DungeonPartyFinderRoomContentUpdateMessage();

  uint dungeonId;
  QList<DungeonPartyFinderPlayer> addedPlayers;
  QList<double> removedPlayersIds;
};

#endif // DUNGEONPARTYFINDERROOMCONTENTUPDATEMESSAGE_H