#include "PaddockBuyResultMessage.h"

void PaddockBuyResultMessage::serialize(Writer *param1)
{
  this->serializeAs_PaddockBuyResultMessage(param1);
}

void PaddockBuyResultMessage::serializeAs_PaddockBuyResultMessage(Writer *param1)
{
  param1->writeInt((int)this->paddockId);
  param1->writeBool(this->bought);
  if(this->realPrice < 0)
  {
    qDebug()<<"ERREUR - PaddockBuyResultMessage -"<<"Forbidden value (" << this->realPrice << ") on element realPrice.";
  }
  else
  {
    param1->writeVarInt((int)this->realPrice);
    return;
  }
}

void PaddockBuyResultMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PaddockBuyResultMessage(param1);
}

void PaddockBuyResultMessage::deserializeAs_PaddockBuyResultMessage(Reader *param1)
{
  this->paddockId = param1->readInt();
  this->bought = param1->readBool();
  this->realPrice = param1->readVarUhInt();
  if(this->realPrice < 0)
  {
    qDebug()<<"ERREUR - PaddockBuyResultMessage -"<<"Forbidden value (" << this->realPrice << ") on element of PaddockBuyResultMessage.realPrice.";
  }
  else
  {
    return;
  }
}

PaddockBuyResultMessage::PaddockBuyResultMessage()
{
  m_type = MessageEnum::PADDOCKBUYRESULTMESSAGE;
}

