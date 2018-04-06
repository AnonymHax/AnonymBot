#ifndef SUBSCRIPTIONLIMITATIONMESSAGE_H
#define SUBSCRIPTIONLIMITATIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class SubscriptionLimitationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SubscriptionLimitationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SubscriptionLimitationMessage(Reader *param1);
  SubscriptionLimitationMessage();

  uint reason;
};

#endif // SUBSCRIPTIONLIMITATIONMESSAGE_H