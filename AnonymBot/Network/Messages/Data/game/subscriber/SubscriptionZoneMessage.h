#ifndef SUBSCRIPTIONZONEMESSAGE_H
#define SUBSCRIPTIONZONEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class SubscriptionZoneMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SubscriptionZoneMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SubscriptionZoneMessage(Reader *param1);
  SubscriptionZoneMessage();

  bool active;
};

#endif // SUBSCRIPTIONZONEMESSAGE_H