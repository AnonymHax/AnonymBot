#ifndef JOBCRAFTERDIRECTORYENTRYMESSAGE_H
#define JOBCRAFTERDIRECTORYENTRYMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/job/JobCrafterDirectoryEntryPlayerInfo.h"
#include "Network/Classes/Data/game/context/roleplay/job/JobCrafterDirectoryEntryJobInfo.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/job/JobCrafterDirectoryEntryPlayerInfo.h"
#include "Network/Classes/Data/game/context/roleplay/job/JobCrafterDirectoryEntryJobInfo.h"
#include "Network/Classes/Data/game/look/EntityLook.h"

class JobCrafterDirectoryEntryMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_JobCrafterDirectoryEntryMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_JobCrafterDirectoryEntryMessage(Reader *param1);
  JobCrafterDirectoryEntryMessage();

  QSharedPointer<JobCrafterDirectoryEntryPlayerInfo> playerInfo;
  QList<JobCrafterDirectoryEntryJobInfo> jobInfoList;
  QSharedPointer<EntityLook> playerLook;
};

#endif // JOBCRAFTERDIRECTORYENTRYMESSAGE_H