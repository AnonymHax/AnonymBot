#ifndef OBJECTSDELETEDMESSAGE_H
#define OBJECTSDELETEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ObjectsDeletedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectsDeletedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectsDeletedMessage(Reader *param1);
  ObjectsDeletedMessage();

  QList<uint> objectUID;
};

#endif // OBJECTSDELETEDMESSAGE_H