#ifndef OBJECTFEEDMESSAGE_H
#define OBJECTFEEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ObjectFeedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectFeedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectFeedMessage(Reader *param1);
  ObjectFeedMessage();

  uint objectUID;
  uint foodUID;
  uint foodQuantity;
};

#endif // OBJECTFEEDMESSAGE_H