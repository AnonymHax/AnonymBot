#ifndef MAILSTATUSMESSAGE_H
#define MAILSTATUSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MailStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MailStatusMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MailStatusMessage(Reader *param1);
  MailStatusMessage();

  uint unread;
  uint total;
};

#endif // MAILSTATUSMESSAGE_H