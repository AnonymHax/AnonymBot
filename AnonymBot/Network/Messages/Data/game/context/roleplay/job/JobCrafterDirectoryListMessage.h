#ifndef JOBCRAFTERDIRECTORYLISTMESSAGE_H
#define JOBCRAFTERDIRECTORYLISTMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/job/JobCrafterDirectoryListEntry.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/job/JobCrafterDirectoryListEntry.h"

class JobCrafterDirectoryListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_JobCrafterDirectoryListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_JobCrafterDirectoryListMessage(Reader *param1);
  JobCrafterDirectoryListMessage();

  QList<QSharedPointer<JobCrafterDirectoryListEntry>> listEntries;
};

#endif // JOBCRAFTERDIRECTORYLISTMESSAGE_H