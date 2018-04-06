#include "JobDescription.h"

void JobDescription::serialize(Writer *param1)
{
  this->serializeAs_JobDescription(param1);
}

void JobDescription::serializeAs_JobDescription(Writer *param1)
{
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobDescription -"<<"Forbidden value (" << this->jobId << ") on element jobId.";
  }
  else
  {
    param1->writeByte(this->jobId);
    param1->writeShort((short)this->skills.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->skills.size())
    {
      param1->writeShort((short)qSharedPointerCast<SkillActionDescription>(this->skills[_loc2_])->getTypes().last());
      qSharedPointerCast<SkillActionDescription>(this->skills[_loc2_])->serialize(param1);
      _loc2_++;
    }
    return;
  }
}

void JobDescription::deserialize(Reader *param1)
{
  this->deserializeAs_JobDescription(param1);
}

void JobDescription::deserializeAs_JobDescription(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<SkillActionDescription> _loc5_ ;
  this->jobId = param1->readByte();
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobDescription -"<<"Forbidden value (" << this->jobId << ") on element of JobDescription.jobId.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = param1->readUShort();
      _loc5_ = qSharedPointerCast<SkillActionDescription>(ClassManagerSingleton::get()->getClass(_loc4_));
      _loc5_->deserialize(param1);
      this->skills.append(_loc5_);
      _loc3_++;
    }
    return;
  }
}

JobDescription::JobDescription()
{
  m_types<<ClassEnum::JOBDESCRIPTION;
}

bool JobDescription::operator==(const JobDescription &compared)
{
  if(jobId == compared.jobId)
  if(skills == compared.skills)
  return true;
  
  return false;
}

