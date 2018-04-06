#ifndef GUESTLIMITATIONMESSAGE_H
#define GUESTLIMITATIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuestLimitationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuestLimitationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuestLimitationMessage(Reader *param1);
  GuestLimitationMessage();

  uint reason;
};

#endif // GUESTLIMITATIONMESSAGE_H