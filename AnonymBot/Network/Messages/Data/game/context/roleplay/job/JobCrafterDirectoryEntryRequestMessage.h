#ifndef JOBCRAFTERDIRECTORYENTRYREQUESTMESSAGE_H
#define JOBCRAFTERDIRECTORYENTRYREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class JobCrafterDirectoryEntryRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_JobCrafterDirectoryEntryRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_JobCrafterDirectoryEntryRequestMessage(Reader *param1);
  JobCrafterDirectoryEntryRequestMessage();

  double playerId;
};

#endif // JOBCRAFTERDIRECTORYENTRYREQUESTMESSAGE_H