#include "JobCrafterDirectorySettings.h"

void JobCrafterDirectorySettings::serialize(Writer *param1)
{
  this->serializeAs_JobCrafterDirectorySettings(param1);
}

void JobCrafterDirectorySettings::serializeAs_JobCrafterDirectorySettings(Writer *param1)
{
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobCrafterDirectorySettings -"<<"Forbidden value (" << this->jobId << ") on element jobId.";
  }
  else
  {
    param1->writeByte(this->jobId);
    if(this->minLevel < 0 || this->minLevel > 255)
    {
      qDebug()<<"ERREUR - JobCrafterDirectorySettings -"<<"Forbidden value (" << this->minLevel << ") on element minLevel.";
    }
    else
    {
      param1->writeByte(this->minLevel);
      param1->writeBool(this->free);
      return;
    }
  }
}

void JobCrafterDirectorySettings::deserialize(Reader *param1)
{
  this->deserializeAs_JobCrafterDirectorySettings(param1);
}

void JobCrafterDirectorySettings::deserializeAs_JobCrafterDirectorySettings(Reader *param1)
{
  this->jobId = param1->readByte();
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobCrafterDirectorySettings -"<<"Forbidden value (" << this->jobId << ") on element of JobCrafterDirectorySettings.jobId.";
  }
  else
  {
    this->minLevel = param1->readUByte();
    if(this->minLevel < 0 || this->minLevel > 255)
    {
      qDebug()<<"ERREUR - JobCrafterDirectorySettings -"<<"Forbidden value (" << this->minLevel << ") on element of JobCrafterDirectorySettings.minLevel.";
    }
    else
    {
      this->free = param1->readBool();
      return;
    }
  }
}

JobCrafterDirectorySettings::JobCrafterDirectorySettings()
{
  m_types<<ClassEnum::JOBCRAFTERDIRECTORYSETTINGS;
}

bool JobCrafterDirectorySettings::operator==(const JobCrafterDirectorySettings &compared)
{
  if(jobId == compared.jobId)
  if(minLevel == compared.minLevel)
  if(free == compared.free)
  return true;
  
  return false;
}

