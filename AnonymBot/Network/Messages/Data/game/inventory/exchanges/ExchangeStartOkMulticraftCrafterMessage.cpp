#include "ExchangeStartOkMulticraftCrafterMessage.h"

void ExchangeStartOkMulticraftCrafterMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeStartOkMulticraftCrafterMessage(param1);
}

void ExchangeStartOkMulticraftCrafterMessage::serializeAs_ExchangeStartOkMulticraftCrafterMessage(Writer *param1)
{
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkMulticraftCrafterMessage -"<<"Forbidden value (" << this->skillId << ") on element skillId.";
  }
  else
  {
    param1->writeVarInt((int)this->skillId);
    return;
  }
}

void ExchangeStartOkMulticraftCrafterMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeStartOkMulticraftCrafterMessage(param1);
}

void ExchangeStartOkMulticraftCrafterMessage::deserializeAs_ExchangeStartOkMulticraftCrafterMessage(Reader *param1)
{
  this->skillId = param1->readVarUhInt();
  if(this->skillId < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartOkMulticraftCrafterMessage -"<<"Forbidden value (" << this->skillId << ") on element of ExchangeStartOkMulticraftCrafterMessage.skillId.";
  }
  else
  {
    return;
  }
}

ExchangeStartOkMulticraftCrafterMessage::ExchangeStartOkMulticraftCrafterMessage()
{
  m_type = MessageEnum::EXCHANGESTARTOKMULTICRAFTCRAFTERMESSAGE;
}

