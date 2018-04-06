#include "ExchangeMultiCraftCrafterCanUseHisRessourcesMessage.h"

void ExchangeMultiCraftCrafterCanUseHisRessourcesMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeMultiCraftCrafterCanUseHisRessourcesMessage(param1);
}

void ExchangeMultiCraftCrafterCanUseHisRessourcesMessage::serializeAs_ExchangeMultiCraftCrafterCanUseHisRessourcesMessage(Writer *param1)
{
  param1->writeBool(this->allowed);
}

void ExchangeMultiCraftCrafterCanUseHisRessourcesMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeMultiCraftCrafterCanUseHisRessourcesMessage(param1);
}

void ExchangeMultiCraftCrafterCanUseHisRessourcesMessage::deserializeAs_ExchangeMultiCraftCrafterCanUseHisRessourcesMessage(Reader *param1)
{
  this->allowed = param1->readBool();
}

ExchangeMultiCraftCrafterCanUseHisRessourcesMessage::ExchangeMultiCraftCrafterCanUseHisRessourcesMessage()
{
  m_type = MessageEnum::EXCHANGEMULTICRAFTCRAFTERCANUSEHISRESSOURCESMESSAGE;
}

