#ifndef JOBEXPERIENCEMULTIUPDATEMESSAGE_H
#define JOBEXPERIENCEMULTIUPDATEMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/job/JobExperience.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/job/JobExperience.h"

class JobExperienceMultiUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_JobExperienceMultiUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_JobExperienceMultiUpdateMessage(Reader *param1);
  JobExperienceMultiUpdateMessage();

  QList<JobExperience> experiencesUpdate;
};

#endif // JOBEXPERIENCEMULTIUPDATEMESSAGE_H