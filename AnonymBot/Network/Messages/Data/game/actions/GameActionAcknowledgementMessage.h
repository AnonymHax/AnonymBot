#ifndef GAMEACTIONACKNOWLEDGEMENTMESSAGE_H
#define GAMEACTIONACKNOWLEDGEMENTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameActionAcknowledgementMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionAcknowledgementMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionAcknowledgementMessage(Reader *param1);
  GameActionAcknowledgementMessage();

  bool valid;
  int actionId;
};

#endif // GAMEACTIONACKNOWLEDGEMENTMESSAGE_H