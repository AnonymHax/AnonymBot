#ifndef OBJECTMOVEMENTMESSAGE_H
#define OBJECTMOVEMENTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ObjectMovementMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectMovementMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectMovementMessage(Reader *param1);
  ObjectMovementMessage();

  uint objectUID;
  uint position;
};

#endif // OBJECTMOVEMENTMESSAGE_H