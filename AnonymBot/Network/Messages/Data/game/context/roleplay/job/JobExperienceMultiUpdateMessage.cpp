#include "JobExperienceMultiUpdateMessage.h"

void JobExperienceMultiUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_JobExperienceMultiUpdateMessage(param1);
}

void JobExperienceMultiUpdateMessage::serializeAs_JobExperienceMultiUpdateMessage(Writer *param1)
{
  param1->writeShort((short)this->experiencesUpdate.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->experiencesUpdate.size())
  {
    (this->experiencesUpdate[_loc2_]).serializeAs_JobExperience(param1);
    _loc2_++;
  }
}

void JobExperienceMultiUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_JobExperienceMultiUpdateMessage(param1);
}

void JobExperienceMultiUpdateMessage::deserializeAs_JobExperienceMultiUpdateMessage(Reader *param1)
{
  JobExperience _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = JobExperience();
    _loc4_.deserialize(param1);
    this->experiencesUpdate.append(_loc4_);
    _loc3_++;
  }
}

JobExperienceMultiUpdateMessage::JobExperienceMultiUpdateMessage()
{
  m_type = MessageEnum::JOBEXPERIENCEMULTIUPDATEMESSAGE;
}

