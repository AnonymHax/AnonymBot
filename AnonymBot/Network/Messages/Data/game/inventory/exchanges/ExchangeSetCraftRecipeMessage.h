#ifndef EXCHANGESETCRAFTRECIPEMESSAGE_H
#define EXCHANGESETCRAFTRECIPEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeSetCraftRecipeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeSetCraftRecipeMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeSetCraftRecipeMessage(Reader *param1);
  ExchangeSetCraftRecipeMessage();

  uint objectGID;
};

#endif // EXCHANGESETCRAFTRECIPEMESSAGE_H