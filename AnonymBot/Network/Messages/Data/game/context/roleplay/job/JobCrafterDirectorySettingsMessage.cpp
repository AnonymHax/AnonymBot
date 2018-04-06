#include "JobCrafterDirectorySettingsMessage.h"

void JobCrafterDirectorySettingsMessage::serialize(Writer *param1)
{
  this->serializeAs_JobCrafterDirectorySettingsMessage(param1);
}

void JobCrafterDirectorySettingsMessage::serializeAs_JobCrafterDirectorySettingsMessage(Writer *param1)
{
  param1->writeShort((short)this->craftersSettings.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->craftersSettings.size())
  {
    (this->craftersSettings[_loc2_]).serializeAs_JobCrafterDirectorySettings(param1);
    _loc2_++;
  }
}

void JobCrafterDirectorySettingsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_JobCrafterDirectorySettingsMessage(param1);
}

void JobCrafterDirectorySettingsMessage::deserializeAs_JobCrafterDirectorySettingsMessage(Reader *param1)
{
  JobCrafterDirectorySettings _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = JobCrafterDirectorySettings();
    _loc4_.deserialize(param1);
    this->craftersSettings.append(_loc4_);
    _loc3_++;
  }
}

JobCrafterDirectorySettingsMessage::JobCrafterDirectorySettingsMessage()
{
  m_type = MessageEnum::JOBCRAFTERDIRECTORYSETTINGSMESSAGE;
}

