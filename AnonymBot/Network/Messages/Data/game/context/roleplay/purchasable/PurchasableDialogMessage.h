#ifndef PURCHASABLEDIALOGMESSAGE_H
#define PURCHASABLEDIALOGMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PurchasableDialogMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PurchasableDialogMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PurchasableDialogMessage(Reader *param1);
  PurchasableDialogMessage();

  bool buyOrSell;
  uint purchasableId;
  uint price;
};

#endif // PURCHASABLEDIALOGMESSAGE_H