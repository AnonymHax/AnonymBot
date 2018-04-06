#ifndef GAMEFIGHTJOINREQUESTMESSAGE_H
#define GAMEFIGHTJOINREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameFightJoinRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightJoinRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightJoinRequestMessage(Reader *param1);
  GameFightJoinRequestMessage();

  double fighterId;
  int fightId;
};

#endif // GAMEFIGHTJOINREQUESTMESSAGE_H