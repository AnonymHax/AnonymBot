#ifndef OBJECTGROUNDADDEDMESSAGE_H
#define OBJECTGROUNDADDEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ObjectGroundAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectGroundAddedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectGroundAddedMessage(Reader *param1);
  ObjectGroundAddedMessage();

  uint cellId;
  uint objectGID;
};

#endif // OBJECTGROUNDADDEDMESSAGE_H