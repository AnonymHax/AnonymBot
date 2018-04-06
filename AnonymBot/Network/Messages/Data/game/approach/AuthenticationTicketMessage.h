#ifndef AUTHENTICATIONTICKETMESSAGE_H
#define AUTHENTICATIONTICKETMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AuthenticationTicketMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AuthenticationTicketMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AuthenticationTicketMessage(Reader *param1);
  AuthenticationTicketMessage();

  QString lang;
  QString ticket;
};

#endif // AUTHENTICATIONTICKETMESSAGE_H