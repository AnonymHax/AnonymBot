#ifndef CURRENTSERVERSTATUSUPDATEMESSAGE_H
#define CURRENTSERVERSTATUSUPDATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CurrentServerStatusUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CurrentServerStatusUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CurrentServerStatusUpdateMessage(Reader *param1);
  CurrentServerStatusUpdateMessage();

  uint status;
};

#endif // CURRENTSERVERSTATUSUPDATEMESSAGE_H