#include "GuildHouseTeleportRequestMessage.h"

void GuildHouseTeleportRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildHouseTeleportRequestMessage(param1);
}

void GuildHouseTeleportRequestMessage::serializeAs_GuildHouseTeleportRequestMessage(Writer *param1)
{
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - GuildHouseTeleportRequestMessage -"<<"Forbidden value (" << this->houseId << ") on element houseId.";
  }
  else
  {
    param1->writeVarInt((int)this->houseId);
    return;
  }
}

void GuildHouseTeleportRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildHouseTeleportRequestMessage(param1);
}

void GuildHouseTeleportRequestMessage::deserializeAs_GuildHouseTeleportRequestMessage(Reader *param1)
{
  this->houseId = param1->readVarUhInt();
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - GuildHouseTeleportRequestMessage -"<<"Forbidden value (" << this->houseId << ") on element of GuildHouseTeleportRequestMessage.houseId.";
  }
  else
  {
    return;
  }
}

GuildHouseTeleportRequestMessage::GuildHouseTeleportRequestMessage()
{
  m_type = MessageEnum::GUILDHOUSETELEPORTREQUESTMESSAGE;
}

