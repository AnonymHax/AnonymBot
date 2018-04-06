#ifndef BASICNOOPERATIONMESSAGE_H
#define BASICNOOPERATIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class BasicNoOperationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_BasicNoOperationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_BasicNoOperationMessage(Reader *param1);
  BasicNoOperationMessage();
};

#endif // BASICNOOPERATIONMESSAGE_H