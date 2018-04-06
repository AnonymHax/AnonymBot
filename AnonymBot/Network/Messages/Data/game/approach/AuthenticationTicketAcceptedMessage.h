#ifndef AUTHENTICATIONTICKETACCEPTEDMESSAGE_H
#define AUTHENTICATIONTICKETACCEPTEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AuthenticationTicketAcceptedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AuthenticationTicketAcceptedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AuthenticationTicketAcceptedMessage(Reader *param1);
  AuthenticationTicketAcceptedMessage();
};

#endif // AUTHENTICATIONTICKETACCEPTEDMESSAGE_H