#ifndef GAMEFIGHTOPTIONSTATEUPDATEMESSAGE_H
#define GAMEFIGHTOPTIONSTATEUPDATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameFightOptionStateUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightOptionStateUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightOptionStateUpdateMessage(Reader *param1);
  GameFightOptionStateUpdateMessage();

  uint fightId;
  uint teamId;
  uint option;
  bool state;
};

#endif // GAMEFIGHTOPTIONSTATEUPDATEMESSAGE_H