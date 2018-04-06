#ifndef PRISMINFOJOINLEAVEREQUESTMESSAGE_H
#define PRISMINFOJOINLEAVEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PrismInfoJoinLeaveRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismInfoJoinLeaveRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismInfoJoinLeaveRequestMessage(Reader *param1);
  PrismInfoJoinLeaveRequestMessage();

  bool join;
};

#endif // PRISMINFOJOINLEAVEREQUESTMESSAGE_H