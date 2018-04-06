#ifndef JOBCRAFTERDIRECTORYSETTINGSMESSAGE_H
#define JOBCRAFTERDIRECTORYSETTINGSMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/job/JobCrafterDirectorySettings.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/job/JobCrafterDirectorySettings.h"

class JobCrafterDirectorySettingsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_JobCrafterDirectorySettingsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_JobCrafterDirectorySettingsMessage(Reader *param1);
  JobCrafterDirectorySettingsMessage();

  QList<JobCrafterDirectorySettings> craftersSettings;
};

#endif // JOBCRAFTERDIRECTORYSETTINGSMESSAGE_H