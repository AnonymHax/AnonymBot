#ifndef JOBBOOKSUBSCRIBEREQUESTMESSAGE_H
#define JOBBOOKSUBSCRIBEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class JobBookSubscribeRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_JobBookSubscribeRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_JobBookSubscribeRequestMessage(Reader *param1);
  JobBookSubscribeRequestMessage();

  QList<uint> jobIds;
};

#endif // JOBBOOKSUBSCRIBEREQUESTMESSAGE_H