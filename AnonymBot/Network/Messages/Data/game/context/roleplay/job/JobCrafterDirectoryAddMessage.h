#ifndef JOBCRAFTERDIRECTORYADDMESSAGE_H
#define JOBCRAFTERDIRECTORYADDMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/job/JobCrafterDirectoryListEntry.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/job/JobCrafterDirectoryListEntry.h"

class JobCrafterDirectoryAddMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_JobCrafterDirectoryAddMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_JobCrafterDirectoryAddMessage(Reader *param1);
  JobCrafterDirectoryAddMessage();

  QSharedPointer<JobCrafterDirectoryListEntry> listEntry;
};

#endif // JOBCRAFTERDIRECTORYADDMESSAGE_H