#ifndef EXCHANGEBIDHOUSETYPEMESSAGE_H
#define EXCHANGEBIDHOUSETYPEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeBidHouseTypeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeBidHouseTypeMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeBidHouseTypeMessage(Reader *param1);
  ExchangeBidHouseTypeMessage();

  uint type;
};

#endif // EXCHANGEBIDHOUSETYPEMESSAGE_H