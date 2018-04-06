#ifndef STOPTOLISTENRUNNINGFIGHTREQUESTMESSAGE_H
#define STOPTOLISTENRUNNINGFIGHTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class StopToListenRunningFightRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_StopToListenRunningFightRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_StopToListenRunningFightRequestMessage(Reader *param1);
  StopToListenRunningFightRequestMessage();
};

#endif // STOPTOLISTENRUNNINGFIGHTREQUESTMESSAGE_H