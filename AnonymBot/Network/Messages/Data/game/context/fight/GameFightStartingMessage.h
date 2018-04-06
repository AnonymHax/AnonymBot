#ifndef GAMEFIGHTSTARTINGMESSAGE_H
#define GAMEFIGHTSTARTINGMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameFightStartingMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightStartingMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightStartingMessage(Reader *param1);
  GameFightStartingMessage();

  uint fightType;
  double attackerId;
  double defenderId;
};

#endif // GAMEFIGHTSTARTINGMESSAGE_H