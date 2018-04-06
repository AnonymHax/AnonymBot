#ifndef JOBCRAFTERDIRECTORYLISTENTRY_H
#define JOBCRAFTERDIRECTORYLISTENTRY_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/job/JobCrafterDirectoryEntryPlayerInfo.h"
#include "Network/Classes/Data/game/context/roleplay/job/JobCrafterDirectoryEntryJobInfo.h"

class JobCrafterDirectoryListEntry : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_JobCrafterDirectoryListEntry(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_JobCrafterDirectoryListEntry(Reader *param1);
  JobCrafterDirectoryListEntry();
  bool operator==(const JobCrafterDirectoryListEntry &compared);

  QSharedPointer<JobCrafterDirectoryEntryPlayerInfo> playerInfo;
  JobCrafterDirectoryEntryJobInfo jobInfo;
};

#endif // JOBCRAFTERDIRECTORYLISTENTRY_H