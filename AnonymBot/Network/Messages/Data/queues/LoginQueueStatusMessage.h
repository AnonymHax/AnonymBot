#ifndef LOGINQUEUESTATUSMESSAGE_H
#define LOGINQUEUESTATUSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class LoginQueueStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_LoginQueueStatusMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_LoginQueueStatusMessage(Reader *param1);
  LoginQueueStatusMessage();

  uint position;
  uint total;
};

#endif // LOGINQUEUESTATUSMESSAGE_H