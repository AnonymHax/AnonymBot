#include "JobCrafterDirectoryListRequestMessage.h"

void JobCrafterDirectoryListRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_JobCrafterDirectoryListRequestMessage(param1);
}

void JobCrafterDirectoryListRequestMessage::serializeAs_JobCrafterDirectoryListRequestMessage(Writer *param1)
{
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryListRequestMessage -"<<"Forbidden value (" << this->jobId << ") on element jobId.";
  }
  else
  {
    param1->writeByte(this->jobId);
    return;
  }
}

void JobCrafterDirectoryListRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_JobCrafterDirectoryListRequestMessage(param1);
}

void JobCrafterDirectoryListRequestMessage::deserializeAs_JobCrafterDirectoryListRequestMessage(Reader *param1)
{
  this->jobId = param1->readByte();
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryListRequestMessage -"<<"Forbidden value (" << this->jobId << ") on element of JobCrafterDirectoryListRequestMessage.jobId.";
  }
  else
  {
    return;
  }
}

JobCrafterDirectoryListRequestMessage::JobCrafterDirectoryListRequestMessage()
{
  m_type = MessageEnum::JOBCRAFTERDIRECTORYLISTREQUESTMESSAGE;
}

