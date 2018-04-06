#ifndef EDITHAVENBAGREQUESTMESSAGE_H
#define EDITHAVENBAGREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class EditHavenBagRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_EditHavenBagRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_EditHavenBagRequestMessage(Reader *param1);
  EditHavenBagRequestMessage();
};

#endif // EDITHAVENBAGREQUESTMESSAGE_H