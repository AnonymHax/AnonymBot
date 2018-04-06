#ifndef GAMEFIGHTREADYMESSAGE_H
#define GAMEFIGHTREADYMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameFightReadyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightReadyMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightReadyMessage(Reader *param1);
  GameFightReadyMessage();

  bool isReady;
};

#endif // GAMEFIGHTREADYMESSAGE_H