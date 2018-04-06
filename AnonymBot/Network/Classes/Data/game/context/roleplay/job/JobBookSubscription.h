#ifndef JOBBOOKSUBSCRIPTION_H
#define JOBBOOKSUBSCRIPTION_H

#include "Network/Classes/AbstractClass.h"

class JobBookSubscription : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_JobBookSubscription(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_JobBookSubscription(Reader *param1);
  JobBookSubscription();
  bool operator==(const JobBookSubscription &compared);

  uint jobId;
  bool subscribed;
};

#endif // JOBBOOKSUBSCRIPTION_H