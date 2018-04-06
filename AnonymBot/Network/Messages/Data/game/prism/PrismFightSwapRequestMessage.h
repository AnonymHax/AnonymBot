#ifndef PRISMFIGHTSWAPREQUESTMESSAGE_H
#define PRISMFIGHTSWAPREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PrismFightSwapRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismFightSwapRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismFightSwapRequestMessage(Reader *param1);
  PrismFightSwapRequestMessage();

  uint subAreaId;
  double targetId;
};

#endif // PRISMFIGHTSWAPREQUESTMESSAGE_H