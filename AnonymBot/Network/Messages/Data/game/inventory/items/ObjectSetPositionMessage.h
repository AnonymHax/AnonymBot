#ifndef OBJECTSETPOSITIONMESSAGE_H
#define OBJECTSETPOSITIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ObjectSetPositionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectSetPositionMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectSetPositionMessage(Reader *param1);
  ObjectSetPositionMessage();

  uint objectUID;
  uint position;
  uint quantity;
};

#endif // OBJECTSETPOSITIONMESSAGE_H