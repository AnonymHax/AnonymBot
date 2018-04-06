#ifndef OBJECTDROPMESSAGE_H
#define OBJECTDROPMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ObjectDropMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectDropMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectDropMessage(Reader *param1);
  ObjectDropMessage();

  uint objectUID;
  uint quantity;
};

#endif // OBJECTDROPMESSAGE_H