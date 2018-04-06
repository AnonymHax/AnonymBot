#ifndef GAMECONTEXTQUITMESSAGE_H
#define GAMECONTEXTQUITMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameContextQuitMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameContextQuitMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameContextQuitMessage(Reader *param1);
  GameContextQuitMessage();
};

#endif // GAMECONTEXTQUITMESSAGE_H