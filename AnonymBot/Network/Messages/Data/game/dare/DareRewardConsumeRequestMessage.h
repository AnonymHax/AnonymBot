#ifndef DAREREWARDCONSUMEREQUESTMESSAGE_H
#define DAREREWARDCONSUMEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DareRewardConsumeRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DareRewardConsumeRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DareRewardConsumeRequestMessage(Reader *param1);
  DareRewardConsumeRequestMessage();

  double dareId;
  uint type;
};

#endif // DAREREWARDCONSUMEREQUESTMESSAGE_H