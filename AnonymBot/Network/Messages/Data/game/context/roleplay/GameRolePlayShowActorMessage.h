#ifndef GAMEROLEPLAYSHOWACTORMESSAGE_H
#define GAMEROLEPLAYSHOWACTORMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/GameRolePlayActorInformations.h"
#include "Network/Classes/ClassManager.h"

class GameRolePlayShowActorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayShowActorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayShowActorMessage(Reader *param1);
  GameRolePlayShowActorMessage();

  QSharedPointer<GameRolePlayActorInformations> informations;
};

#endif // GAMEROLEPLAYSHOWACTORMESSAGE_H