#ifndef GAMEROLEPLAYSHOWACTORWITHEVENTMESSAGE_H
#define GAMEROLEPLAYSHOWACTORWITHEVENTMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/GameRolePlayShowActorMessage.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"

class GameRolePlayShowActorWithEventMessage : public GameRolePlayShowActorMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayShowActorWithEventMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayShowActorWithEventMessage(Reader *param1);
  GameRolePlayShowActorWithEventMessage();

  uint actorEventId;
};

#endif // GAMEROLEPLAYSHOWACTORWITHEVENTMESSAGE_H