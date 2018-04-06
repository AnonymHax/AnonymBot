#ifndef MAPNPCSQUESTSTATUSUPDATEMESSAGE_H
#define MAPNPCSQUESTSTATUSUPDATEMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/quest/GameRolePlayNpcQuestFlag.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/quest/GameRolePlayNpcQuestFlag.h"

class MapNpcsQuestStatusUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MapNpcsQuestStatusUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MapNpcsQuestStatusUpdateMessage(Reader *param1);
  MapNpcsQuestStatusUpdateMessage();

  int mapId;
  QList<int> npcsIdsWithQuest;
  QList<GameRolePlayNpcQuestFlag> questFlags;
  QList<int> npcsIdsWithoutQuest;
};

#endif // MAPNPCSQUESTSTATUSUPDATEMESSAGE_H