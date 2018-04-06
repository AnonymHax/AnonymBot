#ifndef EXITHAVENBAGREQUESTMESSAGE_H
#define EXITHAVENBAGREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExitHavenBagRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExitHavenBagRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExitHavenBagRequestMessage(Reader *param1);
  ExitHavenBagRequestMessage();
};

#endif // EXITHAVENBAGREQUESTMESSAGE_H