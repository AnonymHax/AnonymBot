#include "JobCrafterDirectoryDefineSettingsMessage.h"

void JobCrafterDirectoryDefineSettingsMessage::serialize(Writer *param1)
{
  this->serializeAs_JobCrafterDirectoryDefineSettingsMessage(param1);
}

void JobCrafterDirectoryDefineSettingsMessage::serializeAs_JobCrafterDirectoryDefineSettingsMessage(Writer *param1)
{
  this->settings.serializeAs_JobCrafterDirectorySettings(param1);
}

void JobCrafterDirectoryDefineSettingsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_JobCrafterDirectoryDefineSettingsMessage(param1);
}

void JobCrafterDirectoryDefineSettingsMessage::deserializeAs_JobCrafterDirectoryDefineSettingsMessage(Reader *param1)
{
  this->settings = JobCrafterDirectorySettings();
  this->settings.deserialize(param1);
}

JobCrafterDirectoryDefineSettingsMessage::JobCrafterDirectoryDefineSettingsMessage()
{
  m_type = MessageEnum::JOBCRAFTERDIRECTORYDEFINESETTINGSMESSAGE;
}

