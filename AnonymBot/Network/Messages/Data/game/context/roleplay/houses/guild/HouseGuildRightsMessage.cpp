#include "HouseGuildRightsMessage.h"

void HouseGuildRightsMessage::serialize(Writer *param1)
{
  this->serializeAs_HouseGuildRightsMessage(param1);
}

void HouseGuildRightsMessage::serializeAs_HouseGuildRightsMessage(Writer *param1)
{
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseGuildRightsMessage -"<<"Forbidden value (" << this->houseId << ") on element houseId.";
  }
  else
  {
    param1->writeVarInt((int)this->houseId);
    this->guildInfo->serializeAs_GuildInformations(param1);
    if(this->rights < 0)
    {
      qDebug()<<"ERREUR - HouseGuildRightsMessage -"<<"Forbidden value (" << this->rights << ") on element rights.";
    }
    else
    {
      param1->writeVarInt((int)this->rights);
      return;
    }
  }
}

void HouseGuildRightsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_HouseGuildRightsMessage(param1);
}

void HouseGuildRightsMessage::deserializeAs_HouseGuildRightsMessage(Reader *param1)
{
  this->houseId = param1->readVarUhInt();
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseGuildRightsMessage -"<<"Forbidden value (" << this->houseId << ") on element of HouseGuildRightsMessage.houseId.";
  }
  else
  {
    this->guildInfo = QSharedPointer<GuildInformations>(new GuildInformations() );
    this->guildInfo->deserialize(param1);
    this->rights = param1->readVarUhInt();
    if(this->rights < 0)
    {
      qDebug()<<"ERREUR - HouseGuildRightsMessage -"<<"Forbidden value (" << this->rights << ") on element of HouseGuildRightsMessage.rights.";
    }
    else
    {
      return;
    }
  }
}

HouseGuildRightsMessage::HouseGuildRightsMessage()
{
  m_type = MessageEnum::HOUSEGUILDRIGHTSMESSAGE;
}

