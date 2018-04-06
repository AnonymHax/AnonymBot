#ifndef JOBCRAFTERDIRECTORYREMOVEMESSAGE_H
#define JOBCRAFTERDIRECTORYREMOVEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class JobCrafterDirectoryRemoveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_JobCrafterDirectoryRemoveMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_JobCrafterDirectoryRemoveMessage(Reader *param1);
  JobCrafterDirectoryRemoveMessage();

  uint jobId;
  double playerId;
};

#endif // JOBCRAFTERDIRECTORYREMOVEMESSAGE_H