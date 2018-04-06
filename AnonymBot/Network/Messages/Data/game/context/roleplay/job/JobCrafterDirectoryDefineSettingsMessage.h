#ifndef JOBCRAFTERDIRECTORYDEFINESETTINGSMESSAGE_H
#define JOBCRAFTERDIRECTORYDEFINESETTINGSMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/job/JobCrafterDirectorySettings.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/job/JobCrafterDirectorySettings.h"

class JobCrafterDirectoryDefineSettingsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_JobCrafterDirectoryDefineSettingsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_JobCrafterDirectoryDefineSettingsMessage(Reader *param1);
  JobCrafterDirectoryDefineSettingsMessage();

  JobCrafterDirectorySettings settings;
};

#endif // JOBCRAFTERDIRECTORYDEFINESETTINGSMESSAGE_H