#ifndef EXCHANGELEAVEMESSAGE_H
#define EXCHANGELEAVEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/dialog/LeaveDialogMessage.h"

class ExchangeLeaveMessage : public LeaveDialogMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeLeaveMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeLeaveMessage(Reader *param1);
  ExchangeLeaveMessage();

  bool success;
};

#endif // EXCHANGELEAVEMESSAGE_H