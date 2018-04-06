#include "JobCrafterDirectoryListEntry.h"

void JobCrafterDirectoryListEntry::serialize(Writer *param1)
{
  this->serializeAs_JobCrafterDirectoryListEntry(param1);
}

void JobCrafterDirectoryListEntry::serializeAs_JobCrafterDirectoryListEntry(Writer *param1)
{
  this->playerInfo->serializeAs_JobCrafterDirectoryEntryPlayerInfo(param1);
  this->jobInfo.serializeAs_JobCrafterDirectoryEntryJobInfo(param1);
}

void JobCrafterDirectoryListEntry::deserialize(Reader *param1)
{
  this->deserializeAs_JobCrafterDirectoryListEntry(param1);
}

void JobCrafterDirectoryListEntry::deserializeAs_JobCrafterDirectoryListEntry(Reader *param1)
{
  this->playerInfo = QSharedPointer<JobCrafterDirectoryEntryPlayerInfo>(new JobCrafterDirectoryEntryPlayerInfo() );
  this->playerInfo->deserialize(param1);
  this->jobInfo = JobCrafterDirectoryEntryJobInfo();
  this->jobInfo.deserialize(param1);
}

JobCrafterDirectoryListEntry::JobCrafterDirectoryListEntry()
{
  m_types<<ClassEnum::JOBCRAFTERDIRECTORYLISTENTRY;
}

bool JobCrafterDirectoryListEntry::operator==(const JobCrafterDirectoryListEntry &compared)
{
  if(playerInfo == compared.playerInfo)
  if(jobInfo == compared.jobInfo)
  return true;
  
  return false;
}

