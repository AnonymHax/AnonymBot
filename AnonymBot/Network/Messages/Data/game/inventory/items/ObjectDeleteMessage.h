#ifndef OBJECTDELETEMESSAGE_H
#define OBJECTDELETEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ObjectDeleteMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectDeleteMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectDeleteMessage(Reader *param1);
  ObjectDeleteMessage();

  uint objectUID;
  uint quantity;
};

#endif // OBJECTDELETEMESSAGE_H