#include "JobDescriptionMessage.h"

void JobDescriptionMessage::serialize(Writer *param1)
{
  this->serializeAs_JobDescriptionMessage(param1);
}

void JobDescriptionMessage::serializeAs_JobDescriptionMessage(Writer *param1)
{
  param1->writeShort((short)this->jobsDescription.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->jobsDescription.size())
  {
    qSharedPointerCast<JobDescription>(this->jobsDescription[_loc2_])->serializeAs_JobDescription(param1);
    _loc2_++;
  }
}

void JobDescriptionMessage::deserialize(Reader *param1)
{
  this->deserializeAs_JobDescriptionMessage(param1);
}

void JobDescriptionMessage::deserializeAs_JobDescriptionMessage(Reader *param1)
{
  QSharedPointer<JobDescription> _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = QSharedPointer<JobDescription>(new JobDescription() );
    _loc4_->deserialize(param1);
    this->jobsDescription.append(_loc4_);
    _loc3_++;
  }
}

JobDescriptionMessage::JobDescriptionMessage()
{
  m_type = MessageEnum::JOBDESCRIPTIONMESSAGE;
}

