#ifndef HOUSEKICKINDOORMERCHANTREQUESTMESSAGE_H
#define HOUSEKICKINDOORMERCHANTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class HouseKickIndoorMerchantRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HouseKickIndoorMerchantRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HouseKickIndoorMerchantRequestMessage(Reader *param1);
  HouseKickIndoorMerchantRequestMessage();

  uint cellId;
};

#endif // HOUSEKICKINDOORMERCHANTREQUESTMESSAGE_H