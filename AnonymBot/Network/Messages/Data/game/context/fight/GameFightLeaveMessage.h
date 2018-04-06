#ifndef GAMEFIGHTLEAVEMESSAGE_H
#define GAMEFIGHTLEAVEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameFightLeaveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightLeaveMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightLeaveMessage(Reader *param1);
  GameFightLeaveMessage();

  double charId;
};

#endif // GAMEFIGHTLEAVEMESSAGE_H