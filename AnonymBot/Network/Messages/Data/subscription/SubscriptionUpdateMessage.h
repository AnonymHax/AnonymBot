#ifndef SUBSCRIPTIONUPDATEMESSAGE_H
#define SUBSCRIPTIONUPDATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class SubscriptionUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SubscriptionUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SubscriptionUpdateMessage(Reader *param1);
  SubscriptionUpdateMessage();

  double timestamp;
};

#endif // SUBSCRIPTIONUPDATEMESSAGE_H