#ifndef OBJECTJOBADDEDMESSAGE_H
#define OBJECTJOBADDEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ObjectJobAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectJobAddedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectJobAddedMessage(Reader *param1);
  ObjectJobAddedMessage();

  uint jobId;
};

#endif // OBJECTJOBADDEDMESSAGE_H