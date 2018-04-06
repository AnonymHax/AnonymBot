#include "JobCrafterDirectoryListMessage.h"

void JobCrafterDirectoryListMessage::serialize(Writer *param1)
{
  this->serializeAs_JobCrafterDirectoryListMessage(param1);
}

void JobCrafterDirectoryListMessage::serializeAs_JobCrafterDirectoryListMessage(Writer *param1)
{
  param1->writeShort((short)this->listEntries.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->listEntries.size())
  {
    qSharedPointerCast<JobCrafterDirectoryListEntry>(this->listEntries[_loc2_])->serializeAs_JobCrafterDirectoryListEntry(param1);
    _loc2_++;
  }
}

void JobCrafterDirectoryListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_JobCrafterDirectoryListMessage(param1);
}

void JobCrafterDirectoryListMessage::deserializeAs_JobCrafterDirectoryListMessage(Reader *param1)
{
  QSharedPointer<JobCrafterDirectoryListEntry> _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = QSharedPointer<JobCrafterDirectoryListEntry>(new JobCrafterDirectoryListEntry() );
    _loc4_->deserialize(param1);
    this->listEntries.append(_loc4_);
    _loc3_++;
  }
}

JobCrafterDirectoryListMessage::JobCrafterDirectoryListMessage()
{
  m_type = MessageEnum::JOBCRAFTERDIRECTORYLISTMESSAGE;
}

