#ifndef CLIENTYOUAREDRUNKMESSAGE_H
#define CLIENTYOUAREDRUNKMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/debug/DebugInClientMessage.h"

class ClientYouAreDrunkMessage : public DebugInClientMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ClientYouAreDrunkMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ClientYouAreDrunkMessage(Reader *param1);
  ClientYouAreDrunkMessage();
};

#endif // CLIENTYOUAREDRUNKMESSAGE_H