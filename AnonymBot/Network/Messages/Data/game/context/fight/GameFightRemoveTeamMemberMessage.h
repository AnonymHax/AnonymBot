#ifndef GAMEFIGHTREMOVETEAMMEMBERMESSAGE_H
#define GAMEFIGHTREMOVETEAMMEMBERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameFightRemoveTeamMemberMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightRemoveTeamMemberMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightRemoveTeamMemberMessage(Reader *param1);
  GameFightRemoveTeamMemberMessage();

  uint fightId;
  uint teamId;
  double charId;
};

#endif // GAMEFIGHTREMOVETEAMMEMBERMESSAGE_H