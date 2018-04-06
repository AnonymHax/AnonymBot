#include "JobCrafterDirectoryEntryMessage.h"

void JobCrafterDirectoryEntryMessage::serialize(Writer *param1)
{
  this->serializeAs_JobCrafterDirectoryEntryMessage(param1);
}

void JobCrafterDirectoryEntryMessage::serializeAs_JobCrafterDirectoryEntryMessage(Writer *param1)
{
  this->playerInfo->serializeAs_JobCrafterDirectoryEntryPlayerInfo(param1);
  param1->writeShort((short)this->jobInfoList.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->jobInfoList.size())
  {
    (this->jobInfoList[_loc2_]).serializeAs_JobCrafterDirectoryEntryJobInfo(param1);
    _loc2_++;
  }
  this->playerLook->serializeAs_EntityLook(param1);
}

void JobCrafterDirectoryEntryMessage::deserialize(Reader *param1)
{
  this->deserializeAs_JobCrafterDirectoryEntryMessage(param1);
}

void JobCrafterDirectoryEntryMessage::deserializeAs_JobCrafterDirectoryEntryMessage(Reader *param1)
{
  JobCrafterDirectoryEntryJobInfo _loc4_ ;
  this->playerInfo = QSharedPointer<JobCrafterDirectoryEntryPlayerInfo>(new JobCrafterDirectoryEntryPlayerInfo() );
  this->playerInfo->deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = JobCrafterDirectoryEntryJobInfo();
    _loc4_.deserialize(param1);
    this->jobInfoList.append(_loc4_);
    _loc3_++;
  }
  this->playerLook = QSharedPointer<EntityLook>(new EntityLook() );
  this->playerLook->deserialize(param1);
}

JobCrafterDirectoryEntryMessage::JobCrafterDirectoryEntryMessage()
{
  m_type = MessageEnum::JOBCRAFTERDIRECTORYENTRYMESSAGE;
}

