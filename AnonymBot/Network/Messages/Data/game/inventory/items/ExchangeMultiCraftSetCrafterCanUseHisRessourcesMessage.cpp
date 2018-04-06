#include "ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage.h"

void ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage(param1);
}

void ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage::serializeAs_ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage(Writer *param1)
{
  param1->writeBool(this->allow);
}

void ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage(param1);
}

void ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage::deserializeAs_ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage(Reader *param1)
{
  this->allow = param1->readBool();
}

ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage::ExchangeMultiCraftSetCrafterCanUseHisRessourcesMessage()
{
  m_type = MessageEnum::EXCHANGEMULTICRAFTSETCRAFTERCANUSEHISRESSOURCESMESSAGE;
}

