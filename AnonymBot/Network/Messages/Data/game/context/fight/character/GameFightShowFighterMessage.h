#ifndef GAMEFIGHTSHOWFIGHTERMESSAGE_H
#define GAMEFIGHTSHOWFIGHTERMESSAGE_H

#include "Network/Classes/Data/game/context/fight/GameFightFighterInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterInformations.h"
#include "Network/Classes/ClassManager.h"

class GameFightShowFighterMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightShowFighterMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightShowFighterMessage(Reader *param1);
  GameFightShowFighterMessage();

  QSharedPointer<GameFightFighterInformations> informations;
};

#endif // GAMEFIGHTSHOWFIGHTERMESSAGE_H