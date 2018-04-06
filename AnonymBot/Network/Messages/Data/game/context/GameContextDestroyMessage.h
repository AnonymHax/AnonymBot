#ifndef GAMECONTEXTDESTROYMESSAGE_H
#define GAMECONTEXTDESTROYMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameContextDestroyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameContextDestroyMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameContextDestroyMessage(Reader *param1);
  GameContextDestroyMessage();
};

#endif // GAMECONTEXTDESTROYMESSAGE_H