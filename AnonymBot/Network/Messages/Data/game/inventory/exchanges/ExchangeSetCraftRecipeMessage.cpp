#include "ExchangeSetCraftRecipeMessage.h"

void ExchangeSetCraftRecipeMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeSetCraftRecipeMessage(param1);
}

void ExchangeSetCraftRecipeMessage::serializeAs_ExchangeSetCraftRecipeMessage(Writer *param1)
{
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ExchangeSetCraftRecipeMessage -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
  }
  else
  {
    param1->writeVarShort((int)this->objectGID);
    return;
  }
}

void ExchangeSetCraftRecipeMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeSetCraftRecipeMessage(param1);
}

void ExchangeSetCraftRecipeMessage::deserializeAs_ExchangeSetCraftRecipeMessage(Reader *param1)
{
  this->objectGID = param1->readVarUhShort();
  if(this->objectGID < 0)
  {
    qDebug()<<"ERREUR - ExchangeSetCraftRecipeMessage -"<<"Forbidden value (" << this->objectGID << ") on element of ExchangeSetCraftRecipeMessage.objectGID.";
  }
  else
  {
    return;
  }
}

ExchangeSetCraftRecipeMessage::ExchangeSetCraftRecipeMessage()
{
  m_type = MessageEnum::EXCHANGESETCRAFTRECIPEMESSAGE;
}

