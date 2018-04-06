#ifndef GAMEFIGHTJOINMESSAGE_H
#define GAMEFIGHTJOINMESSAGE_H

#include "System/Tools/IO/BooleanByteWrapper.h"
#include "Network/Messages/AbstractMessage.h"
#include "System/Tools/IO/BooleanByteWrapper.h"

class GameFightJoinMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightJoinMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightJoinMessage(Reader *param1);
  GameFightJoinMessage();

  bool isTeamPhase;
  bool canBeCancelled;
  bool canSayReady;
  bool isFightStarted;
  uint timeMaxBeforeFightStart;
  uint fightType;
};

#endif // GAMEFIGHTJOINMESSAGE_H