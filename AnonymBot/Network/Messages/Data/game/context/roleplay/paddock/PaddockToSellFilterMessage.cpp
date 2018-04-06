#include "PaddockToSellFilterMessage.h"

void PaddockToSellFilterMessage::serialize(Writer *param1)
{
  this->serializeAs_PaddockToSellFilterMessage(param1);
}

void PaddockToSellFilterMessage::serializeAs_PaddockToSellFilterMessage(Writer *param1)
{
  param1->writeInt((int)this->areaId);
  param1->writeByte(this->atLeastNbMount);
  param1->writeByte(this->atLeastNbMachine);
  if(this->maxPrice < 0)
  {
    qDebug()<<"ERREUR - PaddockToSellFilterMessage -"<<"Forbidden value (" << this->maxPrice << ") on element maxPrice.";
  }
  else
  {
    param1->writeVarInt((int)this->maxPrice);
    return;
  }
}

void PaddockToSellFilterMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PaddockToSellFilterMessage(param1);
}

void PaddockToSellFilterMessage::deserializeAs_PaddockToSellFilterMessage(Reader *param1)
{
  this->areaId = param1->readInt();
  this->atLeastNbMount = param1->readByte();
  this->atLeastNbMachine = param1->readByte();
  this->maxPrice = param1->readVarUhInt();
  if(this->maxPrice < 0)
  {
    qDebug()<<"ERREUR - PaddockToSellFilterMessage -"<<"Forbidden value (" << this->maxPrice << ") on element of PaddockToSellFilterMessage.maxPrice.";
  }
  else
  {
    return;
  }
}

PaddockToSellFilterMessage::PaddockToSellFilterMessage()
{
  m_type = MessageEnum::PADDOCKTOSELLFILTERMESSAGE;
}

