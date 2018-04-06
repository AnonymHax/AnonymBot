#ifndef ACCOUNTLINKREQUIREDMESSAGE_H
#define ACCOUNTLINKREQUIREDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AccountLinkRequiredMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AccountLinkRequiredMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AccountLinkRequiredMessage(Reader *param1);
  AccountLinkRequiredMessage();
};

#endif // ACCOUNTLINKREQUIREDMESSAGE_H