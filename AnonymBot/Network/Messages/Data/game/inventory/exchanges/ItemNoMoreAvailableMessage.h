#ifndef ITEMNOMOREAVAILABLEMESSAGE_H
#define ITEMNOMOREAVAILABLEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ItemNoMoreAvailableMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ItemNoMoreAvailableMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ItemNoMoreAvailableMessage(Reader *param1);
  ItemNoMoreAvailableMessage();
};

#endif // ITEMNOMOREAVAILABLEMESSAGE_H