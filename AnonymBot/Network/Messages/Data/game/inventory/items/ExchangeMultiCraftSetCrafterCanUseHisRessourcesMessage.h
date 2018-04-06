#ifndef EXCHANGEMULTICRAFTSETCRAFTERCANUSEHISRESSOURCESMESSAGE_H
#define EXCHANGEMULTICRAFTSETCRAFTERCANUSEHISRESSOURCESMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage(Reader *param1);
  ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage();

  bool allow;
};

#endif // EXCHANGEMULTICRAFTSETCRAFTERCANUSEHISRESSOURCESMESSAGE_H