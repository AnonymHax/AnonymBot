#include "JobExperienceUpdateMessage.h"

void JobExperienceUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_JobExperienceUpdateMessage(param1);
}

void JobExperienceUpdateMessage::serializeAs_JobExperienceUpdateMessage(Writer *param1)
{
  this->experiencesUpdate.serializeAs_JobExperience(param1);
}

void JobExperienceUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_JobExperienceUpdateMessage(param1);
}

void JobExperienceUpdateMessage::deserializeAs_JobExperienceUpdateMessage(Reader *param1)
{
  this->experiencesUpdate = JobExperience();
  this->experiencesUpdate.deserialize(param1);
}

JobExperienceUpdateMessage::JobExperienceUpdateMessage()
{
  m_type = MessageEnum::JOBEXPERIENCEUPDATEMESSAGE;
}

