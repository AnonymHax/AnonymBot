#ifndef PADDOCKSELLBUYDIALOGMESSAGE_H
#define PADDOCKSELLBUYDIALOGMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PaddockSellBuyDialogMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PaddockSellBuyDialogMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PaddockSellBuyDialogMessage(Reader *param1);
  PaddockSellBuyDialogMessage();

  bool bsell;
  uint ownerId;
  uint price;
};

#endif // PADDOCKSELLBUYDIALOGMESSAGE_H