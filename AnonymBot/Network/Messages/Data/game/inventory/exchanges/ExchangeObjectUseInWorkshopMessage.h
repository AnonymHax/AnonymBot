#ifndef EXCHANGEOBJECTUSEINWORKSHOPMESSAGE_H
#define EXCHANGEOBJECTUSEINWORKSHOPMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeObjectUseInWorkshopMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeObjectUseInWorkshopMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeObjectUseInWorkshopMessage(Reader *param1);
  ExchangeObjectUseInWorkshopMessage();

  uint objectUID;
  int quantity;
};

#endif // EXCHANGEOBJECTUSEINWORKSHOPMESSAGE_H