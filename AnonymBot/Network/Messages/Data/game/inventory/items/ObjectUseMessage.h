#ifndef OBJECTUSEMESSAGE_H
#define OBJECTUSEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ObjectUseMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectUseMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectUseMessage(Reader *param1);
  ObjectUseMessage();

  uint objectUID;
};

#endif // OBJECTUSEMESSAGE_H