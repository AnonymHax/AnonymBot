#include "JobCrafterDirectoryRemoveMessage.h"

void JobCrafterDirectoryRemoveMessage::serialize(Writer *param1)
{
  this->serializeAs_JobCrafterDirectoryRemoveMessage(param1);
}

void JobCrafterDirectoryRemoveMessage::serializeAs_JobCrafterDirectoryRemoveMessage(Writer *param1)
{
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryRemoveMessage -"<<"Forbidden value (" << this->jobId << ") on element jobId.";
  }
  else
  {
    param1->writeByte(this->jobId);
    if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - JobCrafterDirectoryRemoveMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
    }
    else
    {
      param1->writeVarLong((double)this->playerId);
      return;
    }
  }
}

void JobCrafterDirectoryRemoveMessage::deserialize(Reader *param1)
{
  this->deserializeAs_JobCrafterDirectoryRemoveMessage(param1);
}

void JobCrafterDirectoryRemoveMessage::deserializeAs_JobCrafterDirectoryRemoveMessage(Reader *param1)
{
  this->jobId = param1->readByte();
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryRemoveMessage -"<<"Forbidden value (" << this->jobId << ") on element of JobCrafterDirectoryRemoveMessage.jobId.";
  }
  else
  {
    this->playerId = param1->readVarUhLong();
    if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - JobCrafterDirectoryRemoveMessage -"<<"Forbidden value (" << this->playerId << ") on element of JobCrafterDirectoryRemoveMessage.playerId.";
    }
    else
    {
      return;
    }
  }
}

JobCrafterDirectoryRemoveMessage::JobCrafterDirectoryRemoveMessage()
{
  m_type = MessageEnum::JOBCRAFTERDIRECTORYREMOVEMESSAGE;
}

