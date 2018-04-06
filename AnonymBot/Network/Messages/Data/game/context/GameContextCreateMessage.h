#ifndef GAMECONTEXTCREATEMESSAGE_H
#define GAMECONTEXTCREATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameContextCreateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameContextCreateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameContextCreateMessage(Reader *param1);
  GameContextCreateMessage();

  uint context;
};

#endif // GAMECONTEXTCREATEMESSAGE_H