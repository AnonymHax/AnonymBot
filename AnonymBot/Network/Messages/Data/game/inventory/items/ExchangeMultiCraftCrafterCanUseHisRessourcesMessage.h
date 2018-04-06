#ifndef EXCHANGEMULTICRAFTCRAFTERCANUSEHISRESSOURCESMESSAGE_H
#define EXCHANGEMULTICRAFTCRAFTERCANUSEHISRESSOURCESMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ExchangeMultiCraftCrafterCanUseHisRessourcesMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeMultiCraftCrafterCanUseHisRessourcesMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeMultiCraftCrafterCanUseHisRessourcesMessage(Reader *param1);
  ExchangeMultiCraftCrafterCanUseHisRessourcesMessage();

  bool allowed;
};

#endif // EXCHANGEMULTICRAFTCRAFTERCANUSEHISRESSOURCESMESSAGE_H