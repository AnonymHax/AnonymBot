#include "GuildHouseRemoveMessage.h"

void GuildHouseRemoveMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildHouseRemoveMessage(param1);
}

void GuildHouseRemoveMessage::serializeAs_GuildHouseRemoveMessage(Writer *param1)
{
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - GuildHouseRemoveMessage -"<<"Forbidden value (" << this->houseId << ") on element houseId.";
  }
  else
  {
    param1->writeVarInt((int)this->houseId);
    return;
  }
}

void GuildHouseRemoveMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildHouseRemoveMessage(param1);
}

void GuildHouseRemoveMessage::deserializeAs_GuildHouseRemoveMessage(Reader *param1)
{
  this->houseId = param1->readVarUhInt();
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - GuildHouseRemoveMessage -"<<"Forbidden value (" << this->houseId << ") on element of GuildHouseRemoveMessage.houseId.";
  }
  else
  {
    return;
  }
}

GuildHouseRemoveMessage::GuildHouseRemoveMessage()
{
  m_type = MessageEnum::GUILDHOUSEREMOVEMESSAGE;
}

