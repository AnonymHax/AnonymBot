#include "JobCrafterDirectoryEntryJobInfo.h"

void JobCrafterDirectoryEntryJobInfo::serialize(Writer *param1)
{
  this->serializeAs_JobCrafterDirectoryEntryJobInfo(param1);
}

void JobCrafterDirectoryEntryJobInfo::serializeAs_JobCrafterDirectoryEntryJobInfo(Writer *param1)
{
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryEntryJobInfo -"<<"Forbidden value (" << this->jobId << ") on element jobId.";
  }
  else
  {
    param1->writeByte(this->jobId);
    if(this->jobLevel < 1 || this->jobLevel > 200)
    {
      qDebug()<<"ERREUR - JobCrafterDirectoryEntryJobInfo -"<<"Forbidden value (" << this->jobLevel << ") on element jobLevel.";
    }
    else
    {
      param1->writeByte(this->jobLevel);
      param1->writeBool(this->free);
      if(this->minLevel < 0 || this->minLevel > 255)
      {
        qDebug()<<"ERREUR - JobCrafterDirectoryEntryJobInfo -"<<"Forbidden value (" << this->minLevel << ") on element minLevel.";
      }
      else
      {
        param1->writeByte(this->minLevel);
        return;
      }
    }
  }
}

void JobCrafterDirectoryEntryJobInfo::deserialize(Reader *param1)
{
  this->deserializeAs_JobCrafterDirectoryEntryJobInfo(param1);
}

void JobCrafterDirectoryEntryJobInfo::deserializeAs_JobCrafterDirectoryEntryJobInfo(Reader *param1)
{
  this->jobId = param1->readByte();
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryEntryJobInfo -"<<"Forbidden value (" << this->jobId << ") on element of JobCrafterDirectoryEntryJobInfo.jobId.";
  }
  else
  {
    this->jobLevel = param1->readUByte();
    if(this->jobLevel < 1 || this->jobLevel > 200)
    {
      qDebug()<<"ERREUR - JobCrafterDirectoryEntryJobInfo -"<<"Forbidden value (" << this->jobLevel << ") on element of JobCrafterDirectoryEntryJobInfo.jobLevel.";
    }
    else
    {
      this->free = param1->readBool();
      this->minLevel = param1->readUByte();
      if(this->minLevel < 0 || this->minLevel > 255)
      {
        qDebug()<<"ERREUR - JobCrafterDirectoryEntryJobInfo -"<<"Forbidden value (" << this->minLevel << ") on element of JobCrafterDirectoryEntryJobInfo.minLevel.";
      }
      else
      {
        return;
      }
    }
  }
}

JobCrafterDirectoryEntryJobInfo::JobCrafterDirectoryEntryJobInfo()
{
  m_types<<ClassEnum::JOBCRAFTERDIRECTORYENTRYJOBINFO;
}

bool JobCrafterDirectoryEntryJobInfo::operator==(const JobCrafterDirectoryEntryJobInfo &compared)
{
  if(jobId == compared.jobId)
  if(jobLevel == compared.jobLevel)
  if(free == compared.free)
  if(minLevel == compared.minLevel)
  return true;
  
  return false;
}

