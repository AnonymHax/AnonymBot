#ifndef ACCOUNTLOGGINGKICKEDMESSAGE_H
#define ACCOUNTLOGGINGKICKEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AccountLoggingKickedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AccountLoggingKickedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AccountLoggingKickedMessage(Reader *param1);
  AccountLoggingKickedMessage();

  uint days;
  uint hours;
  uint minutes;
};

#endif // ACCOUNTLOGGINGKICKEDMESSAGE_H