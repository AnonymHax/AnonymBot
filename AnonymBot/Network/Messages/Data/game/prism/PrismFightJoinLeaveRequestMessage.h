#ifndef PRISMFIGHTJOINLEAVEREQUESTMESSAGE_H
#define PRISMFIGHTJOINLEAVEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PrismFightJoinLeaveRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismFightJoinLeaveRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismFightJoinLeaveRequestMessage(Reader *param1);
  PrismFightJoinLeaveRequestMessage();

  uint subAreaId;
  bool join;
};

#endif // PRISMFIGHTJOINLEAVEREQUESTMESSAGE_H