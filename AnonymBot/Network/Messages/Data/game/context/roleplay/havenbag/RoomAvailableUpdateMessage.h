#ifndef ROOMAVAILABLEUPDATEMESSAGE_H
#define ROOMAVAILABLEUPDATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class RoomAvailableUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_RoomAvailableUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_RoomAvailableUpdateMessage(Reader *param1);
  RoomAvailableUpdateMessage();

  uint nbRoom;
};

#endif // ROOMAVAILABLEUPDATEMESSAGE_H