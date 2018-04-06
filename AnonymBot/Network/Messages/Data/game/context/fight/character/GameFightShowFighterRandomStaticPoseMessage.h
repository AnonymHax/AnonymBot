#ifndef GAMEFIGHTSHOWFIGHTERRANDOMSTATICPOSEMESSAGE_H
#define GAMEFIGHTSHOWFIGHTERRANDOMSTATICPOSEMESSAGE_H

#include "Network/Classes/Data/game/context/fight/GameFightFighterInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/fight/character/GameFightShowFighterMessage.h"
#include "Network/Classes/Data/game/context/fight/GameFightFighterInformations.h"

class GameFightShowFighterRandomStaticPoseMessage : public GameFightShowFighterMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightShowFighterRandomStaticPoseMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightShowFighterRandomStaticPoseMessage(Reader *param1);
  GameFightShowFighterRandomStaticPoseMessage();
};

#endif // GAMEFIGHTSHOWFIGHTERRANDOMSTATICPOSEMESSAGE_H