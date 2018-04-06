#ifndef PADDOCKBUYREQUESTMESSAGE_H
#define PADDOCKBUYREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PaddockBuyRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PaddockBuyRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PaddockBuyRequestMessage(Reader *param1);
  PaddockBuyRequestMessage();

  uint proposedPrice;
};

#endif // PADDOCKBUYREQUESTMESSAGE_H