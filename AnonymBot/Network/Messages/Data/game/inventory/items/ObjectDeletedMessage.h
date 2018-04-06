#ifndef OBJECTDELETEDMESSAGE_H
#define OBJECTDELETEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ObjectDeletedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectDeletedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectDeletedMessage(Reader *param1);
  ObjectDeletedMessage();

  uint objectUID;
};

#endif // OBJECTDELETEDMESSAGE_H