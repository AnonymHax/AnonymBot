#include "JobCrafterDirectoryAddMessage.h"

void JobCrafterDirectoryAddMessage::serialize(Writer *param1)
{
  this->serializeAs_JobCrafterDirectoryAddMessage(param1);
}

void JobCrafterDirectoryAddMessage::serializeAs_JobCrafterDirectoryAddMessage(Writer *param1)
{
  this->listEntry->serializeAs_JobCrafterDirectoryListEntry(param1);
}

void JobCrafterDirectoryAddMessage::deserialize(Reader *param1)
{
  this->deserializeAs_JobCrafterDirectoryAddMessage(param1);
}

void JobCrafterDirectoryAddMessage::deserializeAs_JobCrafterDirectoryAddMessage(Reader *param1)
{
  this->listEntry = QSharedPointer<JobCrafterDirectoryListEntry>(new JobCrafterDirectoryListEntry() );
  this->listEntry->deserialize(param1);
}

JobCrafterDirectoryAddMessage::JobCrafterDirectoryAddMessage()
{
  m_type = MessageEnum::JOBCRAFTERDIRECTORYADDMESSAGE;
}

