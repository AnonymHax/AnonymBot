#include "ExchangeCraftResultMessage.h"

void ExchangeCraftResultMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeCraftResultMessage(param1);
}

void ExchangeCraftResultMessage::serializeAs_ExchangeCraftResultMessage(Writer *param1)
{
  param1->writeByte(this->craftResult);
}

void ExchangeCraftResultMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeCraftResultMessage(param1);
}

void ExchangeCraftResultMessage::deserializeAs_ExchangeCraftResultMessage(Reader *param1)
{
  this->craftResult = param1->readByte();
  if(this->craftResult < 0)
  {
    qDebug()<<"ERREUR - ExchangeCraftResultMessage -"<<"Forbidden value (" << this->craftResult << ") on element of ExchangeCraftResultMessage.craftResult.";
  }
  else
  {
    return;
  }
}

ExchangeCraftResultMessage::ExchangeCraftResultMessage()
{
  m_type = MessageEnum::EXCHANGECRAFTRESULTMESSAGE;
}

