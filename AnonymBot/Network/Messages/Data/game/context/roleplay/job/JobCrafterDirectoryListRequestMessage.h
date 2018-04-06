#ifndef JOBCRAFTERDIRECTORYLISTREQUESTMESSAGE_H
#define JOBCRAFTERDIRECTORYLISTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class JobCrafterDirectoryListRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_JobCrafterDirectoryListRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_JobCrafterDirectoryListRequestMessage(Reader *param1);
  JobCrafterDirectoryListRequestMessage();

  uint jobId;
};

#endif // JOBCRAFTERDIRECTORYLISTREQUESTMESSAGE_H