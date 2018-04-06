#ifndef GAMECONTEXTCREATEREQUESTMESSAGE_H
#define GAMECONTEXTCREATEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameContextCreateRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameContextCreateRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameContextCreateRequestMessage(Reader *param1);
  GameContextCreateRequestMessage();
};

#endif // GAMECONTEXTCREATEREQUESTMESSAGE_H