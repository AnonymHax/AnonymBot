#ifndef HOUSEBUYREQUESTMESSAGE_H
#define HOUSEBUYREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class HouseBuyRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HouseBuyRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HouseBuyRequestMessage(Reader *param1);
  HouseBuyRequestMessage();

  uint proposedPrice;
};

#endif // HOUSEBUYREQUESTMESSAGE_H