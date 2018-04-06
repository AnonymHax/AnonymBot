#include "HouseGuildShareRequestMessage.h"

void HouseGuildShareRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_HouseGuildShareRequestMessage(param1);
}

void HouseGuildShareRequestMessage::serializeAs_HouseGuildShareRequestMessage(Writer *param1)
{
  param1->writeBool(this->enable);
  if(this->rights < 0)
  {
    qDebug()<<"ERREUR - HouseGuildShareRequestMessage -"<<"Forbidden value (" << this->rights << ") on element rights.";
  }
  else
  {
    param1->writeVarInt((int)this->rights);
    return;
  }
}

void HouseGuildShareRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_HouseGuildShareRequestMessage(param1);
}

void HouseGuildShareRequestMessage::deserializeAs_HouseGuildShareRequestMessage(Reader *param1)
{
  this->enable = param1->readBool();
  this->rights = param1->readVarUhInt();
  if(this->rights < 0)
  {
    qDebug()<<"ERREUR - HouseGuildShareRequestMessage -"<<"Forbidden value (" << this->rights << ") on element of HouseGuildShareRequestMessage.rights.";
  }
  else
  {
    return;
  }
}

HouseGuildShareRequestMessage::HouseGuildShareRequestMessage()
{
  m_type = MessageEnum::HOUSEGUILDSHAREREQUESTMESSAGE;
}

