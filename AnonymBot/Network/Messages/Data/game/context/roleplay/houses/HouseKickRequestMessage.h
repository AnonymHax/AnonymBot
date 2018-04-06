#ifndef HOUSEKICKREQUESTMESSAGE_H
#define HOUSEKICKREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class HouseKickRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HouseKickRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HouseKickRequestMessage(Reader *param1);
  HouseKickRequestMessage();

  double id;
};

#endif // HOUSEKICKREQUESTMESSAGE_H