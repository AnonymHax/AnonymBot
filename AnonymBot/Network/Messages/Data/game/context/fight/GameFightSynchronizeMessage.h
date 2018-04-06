#ifndef GAMEFIGHTSYNCHRONIZEMESSAGE_H
#define GAMEFIGHTSYNCHRONIZEMESSAGE_H

#include "Network/Classes/Data/game/context/fight/GameFightFighterInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterInformations.h"
#include "Network/Classes/ClassManager.h"

class GameFightSynchronizeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightSynchronizeMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightSynchronizeMessage(Reader *param1);
  GameFightSynchronizeMessage();

  QList<QSharedPointer<GameFightFighterInformations>> fighters;
};

#endif // GAMEFIGHTSYNCHRONIZEMESSAGE_H