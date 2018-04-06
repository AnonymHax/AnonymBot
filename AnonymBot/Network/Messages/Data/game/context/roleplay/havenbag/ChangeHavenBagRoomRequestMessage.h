#ifndef CHANGEHAVENBAGROOMREQUESTMESSAGE_H
#define CHANGEHAVENBAGROOMREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ChangeHavenBagRoomRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChangeHavenBagRoomRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChangeHavenBagRoomRequestMessage(Reader *param1);
  ChangeHavenBagRoomRequestMessage();

  uint roomId;
};

#endif // CHANGEHAVENBAGROOMREQUESTMESSAGE_H