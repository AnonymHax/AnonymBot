#ifndef ENTERHAVENBAGREQUESTMESSAGE_H
#define ENTERHAVENBAGREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class EnterHavenBagRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_EnterHavenBagRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_EnterHavenBagRequestMessage(Reader *param1);
  EnterHavenBagRequestMessage();
};

#endif // ENTERHAVENBAGREQUESTMESSAGE_H