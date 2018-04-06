#ifndef ALREADYCONNECTEDMESSAGE_H
#define ALREADYCONNECTEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AlreadyConnectedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AlreadyConnectedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AlreadyConnectedMessage(Reader *param1);
  AlreadyConnectedMessage();
};

#endif // ALREADYCONNECTEDMESSAGE_H