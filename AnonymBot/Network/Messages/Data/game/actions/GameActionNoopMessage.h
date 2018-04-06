#ifndef GAMEACTIONNOOPMESSAGE_H
#define GAMEACTIONNOOPMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameActionNoopMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionNoopMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionNoopMessage(Reader *param1);
  GameActionNoopMessage();
};

#endif // GAMEACTIONNOOPMESSAGE_H