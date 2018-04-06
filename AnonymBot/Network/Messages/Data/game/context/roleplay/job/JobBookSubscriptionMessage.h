#ifndef JOBBOOKSUBSCRIPTIONMESSAGE_H
#define JOBBOOKSUBSCRIPTIONMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/job/JobBookSubscription.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/job/JobBookSubscription.h"

class JobBookSubscriptionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_JobBookSubscriptionMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_JobBookSubscriptionMessage(Reader *param1);
  JobBookSubscriptionMessage();

  QList<JobBookSubscription> subscriptions;
};

#endif // JOBBOOKSUBSCRIPTIONMESSAGE_H