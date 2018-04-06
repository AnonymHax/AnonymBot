#ifndef GAMEFIGHTTURNREADYMESSAGE_H
#define GAMEFIGHTTURNREADYMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameFightTurnReadyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightTurnReadyMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightTurnReadyMessage(Reader *param1);
  GameFightTurnReadyMessage();

  bool isReady;
};

#endif // GAMEFIGHTTURNREADYMESSAGE_H