#ifndef NEWMAILMESSAGE_H
#define NEWMAILMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/web/ankabox/MailStatusMessage.h"

class NewMailMessage : public MailStatusMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_NewMailMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_NewMailMessage(Reader *param1);
  NewMailMessage();

  QList<uint> sendersAccountId;
};

#endif // NEWMAILMESSAGE_H