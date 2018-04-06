#ifndef AUTHENTICATIONTICKETREFUSEDMESSAGE_H
#define AUTHENTICATIONTICKETREFUSEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AuthenticationTicketRefusedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AuthenticationTicketRefusedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AuthenticationTicketRefusedMessage(Reader *param1);
  AuthenticationTicketRefusedMessage();
};

#endif // AUTHENTICATIONTICKETREFUSEDMESSAGE_H