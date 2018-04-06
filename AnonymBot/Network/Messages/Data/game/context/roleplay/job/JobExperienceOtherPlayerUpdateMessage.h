#ifndef JOBEXPERIENCEOTHERPLAYERUPDATEMESSAGE_H
#define JOBEXPERIENCEOTHERPLAYERUPDATEMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/job/JobExperience.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/job/JobExperienceUpdateMessage.h"
#include "Network/Classes/Data/game/context/roleplay/job/JobExperience.h"

class JobExperienceOtherPlayerUpdateMessage : public JobExperienceUpdateMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_JobExperienceOtherPlayerUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_JobExperienceOtherPlayerUpdateMessage(Reader *param1);
  JobExperienceOtherPlayerUpdateMessage();

  double playerId;
};

#endif // JOBEXPERIENCEOTHERPLAYERUPDATEMESSAGE_H