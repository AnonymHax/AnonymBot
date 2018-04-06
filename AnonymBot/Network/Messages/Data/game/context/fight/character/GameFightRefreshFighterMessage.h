#ifndef GAMEFIGHTREFRESHFIGHTERMESSAGE_H
#define GAMEFIGHTREFRESHFIGHTERMESSAGE_H

#include "Network/Classes/Data/game/context/GameContextActorInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/GameContextActorInformations.h"
#include "Network/Classes/ClassManager.h"

class GameFightRefreshFighterMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightRefreshFighterMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightRefreshFighterMessage(Reader *param1);
  GameFightRefreshFighterMessage();

  QSharedPointer<GameContextActorInformations> informations;
};

#endif // GAMEFIGHTREFRESHFIGHTERMESSAGE_H