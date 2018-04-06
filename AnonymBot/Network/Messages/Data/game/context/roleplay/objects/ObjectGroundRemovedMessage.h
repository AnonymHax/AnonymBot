#ifndef OBJECTGROUNDREMOVEDMESSAGE_H
#define OBJECTGROUNDREMOVEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ObjectGroundRemovedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectGroundRemovedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectGroundRemovedMessage(Reader *param1);
  ObjectGroundRemovedMessage();

  uint cell;
};

#endif // OBJECTGROUNDREMOVEDMESSAGE_H