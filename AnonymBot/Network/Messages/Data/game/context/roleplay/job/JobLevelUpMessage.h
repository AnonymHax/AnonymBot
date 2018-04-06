#ifndef JOBLEVELUPMESSAGE_H
#define JOBLEVELUPMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/job/JobDescription.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/job/JobDescription.h"

class JobLevelUpMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_JobLevelUpMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_JobLevelUpMessage(Reader *param1);
  JobLevelUpMessage();

  uint newLevel;
  QSharedPointer<JobDescription> jobsDescription;
};

#endif // JOBLEVELUPMESSAGE_H