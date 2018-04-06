#ifndef JOBEXPERIENCEUPDATEMESSAGE_H
#define JOBEXPERIENCEUPDATEMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/job/JobExperience.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/job/JobExperience.h"

class JobExperienceUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_JobExperienceUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_JobExperienceUpdateMessage(Reader *param1);
  JobExperienceUpdateMessage();

  JobExperience experiencesUpdate;
};

#endif // JOBEXPERIENCEUPDATEMESSAGE_H