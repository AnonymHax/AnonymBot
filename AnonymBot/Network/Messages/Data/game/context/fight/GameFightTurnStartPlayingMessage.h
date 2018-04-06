#ifndef GAMEFIGHTTURNSTARTPLAYINGMESSAGE_H
#define GAMEFIGHTTURNSTARTPLAYINGMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameFightTurnStartPlayingMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightTurnStartPlayingMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightTurnStartPlayingMessage(Reader *param1);
  GameFightTurnStartPlayingMessage();
};

#endif // GAMEFIGHTTURNSTARTPLAYINGMESSAGE_H