#ifndef INTERACTIVEUSEREQUESTMESSAGE_H
#define INTERACTIVEUSEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class InteractiveUseRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InteractiveUseRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InteractiveUseRequestMessage(Reader *param1);
  InteractiveUseRequestMessage();

  uint elemId;
  uint skillInstanceUid;
};

#endif // INTERACTIVEUSEREQUESTMESSAGE_H