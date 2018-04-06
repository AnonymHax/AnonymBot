#include "HouseGuildNoneMessage.h"

void HouseGuildNoneMessage::serialize(Writer *param1)
{
  this->serializeAs_HouseGuildNoneMessage(param1);
}

void HouseGuildNoneMessage::serializeAs_HouseGuildNoneMessage(Writer *param1)
{
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseGuildNoneMessage -"<<"Forbidden value (" << this->houseId << ") on element houseId.";
  }
  else
  {
    param1->writeVarInt((int)this->houseId);
    return;
  }
}

void HouseGuildNoneMessage::deserialize(Reader *param1)
{
  this->deserializeAs_HouseGuildNoneMessage(param1);
}

void HouseGuildNoneMessage::deserializeAs_HouseGuildNoneMessage(Reader *param1)
{
  this->houseId = param1->readVarUhInt();
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseGuildNoneMessage -"<<"Forbidden value (" << this->houseId << ") on element of HouseGuildNoneMessage.houseId.";
  }
  else
  {
    return;
  }
}

HouseGuildNoneMessage::HouseGuildNoneMessage()
{
  m_type = MessageEnum::HOUSEGUILDNONEMESSAGE;
}

