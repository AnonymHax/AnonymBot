#ifndef OBJECTQUANTITYMESSAGE_H
#define OBJECTQUANTITYMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ObjectQuantityMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectQuantityMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectQuantityMessage(Reader *param1);
  ObjectQuantityMessage();

  uint objectUID;
  uint quantity;
};

#endif // OBJECTQUANTITYMESSAGE_H