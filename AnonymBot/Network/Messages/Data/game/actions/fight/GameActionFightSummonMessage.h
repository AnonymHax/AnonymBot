#ifndef GAMEACTIONFIGHTSUMMONMESSAGE_H
#define GAMEACTIONFIGHTSUMMONMESSAGE_H

#include "Network/Classes/Data/game/context/fight/GameFightFighterInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterInformations.h"
#include "Network/Classes/ClassManager.h"

class GameActionFightSummonMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightSummonMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightSummonMessage(Reader *param1);
  GameActionFightSummonMessage();

  QList<QSharedPointer<GameFightFighterInformations>> summons;
};

#endif // GAMEACTIONFIGHTSUMMONMESSAGE_H