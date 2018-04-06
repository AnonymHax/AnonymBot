#ifndef HOUSEGUILDNONEMESSAGE_H
#define HOUSEGUILDNONEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class HouseGuildNoneMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HouseGuildNoneMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HouseGuildNoneMessage(Reader *param1);
  HouseGuildNoneMessage();

  uint houseId;
};

#endif // HOUSEGUILDNONEMESSAGE_H