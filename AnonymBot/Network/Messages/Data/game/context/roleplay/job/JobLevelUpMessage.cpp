#include "JobLevelUpMessage.h"

void JobLevelUpMessage::serialize(Writer *param1)
{
  this->serializeAs_JobLevelUpMessage(param1);
}

void JobLevelUpMessage::serializeAs_JobLevelUpMessage(Writer *param1)
{
  if(this->newLevel < 0 || this->newLevel > 255)
  {
    qDebug()<<"ERREUR - JobLevelUpMessage -"<<"Forbidden value (" << this->newLevel << ") on element newLevel.";
  }
  else
  {
    param1->writeByte(this->newLevel);
    this->jobsDescription->serializeAs_JobDescription(param1);
    return;
  }
}

void JobLevelUpMessage::deserialize(Reader *param1)
{
  this->deserializeAs_JobLevelUpMessage(param1);
}

void JobLevelUpMessage::deserializeAs_JobLevelUpMessage(Reader *param1)
{
  this->newLevel = param1->readUByte();
  if(this->newLevel < 0 || this->newLevel > 255)
  {
    qDebug()<<"ERREUR - JobLevelUpMessage -"<<"Forbidden value (" << this->newLevel << ") on element of JobLevelUpMessage.newLevel.";
  }
  else
  {
    this->jobsDescription = QSharedPointer<JobDescription>(new JobDescription() );
    this->jobsDescription->deserialize(param1);
    return;
  }
}

JobLevelUpMessage::JobLevelUpMessage()
{
  m_type = MessageEnum::JOBLEVELUPMESSAGE;
}

