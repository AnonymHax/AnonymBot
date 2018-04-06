#ifndef GAMEROLEPLAYARENAFIGHTANSWERMESSAGE_H
#define GAMEROLEPLAYARENAFIGHTANSWERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameRolePlayArenaFightAnswerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayArenaFightAnswerMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayArenaFightAnswerMessage(Reader *param1);
  GameRolePlayArenaFightAnswerMessage();

  int fightId;
  bool accept;
};

#endif // GAMEROLEPLAYARENAFIGHTANSWERMESSAGE_H