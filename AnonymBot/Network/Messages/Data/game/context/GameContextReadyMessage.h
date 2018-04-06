#ifndef GAMECONTEXTREADYMESSAGE_H
#define GAMECONTEXTREADYMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameContextReadyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameContextReadyMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameContextReadyMessage(Reader *param1);
  GameContextReadyMessage();

  uint mapId;
};

#endif // GAMECONTEXTREADYMESSAGE_H