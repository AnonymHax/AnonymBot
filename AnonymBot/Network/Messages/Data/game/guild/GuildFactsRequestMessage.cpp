#include "GuildFactsRequestMessage.h"

void GuildFactsRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildFactsRequestMessage(param1);
}

void GuildFactsRequestMessage::serializeAs_GuildFactsRequestMessage(Writer *param1)
{
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - GuildFactsRequestMessage -"<<"Forbidden value (" << this->guildId << ") on element guildId.";
  }
  else
  {
    param1->writeVarInt((int)this->guildId);
    return;
  }
}

void GuildFactsRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildFactsRequestMessage(param1);
}

void GuildFactsRequestMessage::deserializeAs_GuildFactsRequestMessage(Reader *param1)
{
  this->guildId = param1->readVarUhInt();
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - GuildFactsRequestMessage -"<<"Forbidden value (" << this->guildId << ") on element of GuildFactsRequestMessage.guildId.";
  }
  else
  {
    return;
  }
}

GuildFactsRequestMessage::GuildFactsRequestMessage()
{
  m_type = MessageEnum::GUILDFACTSREQUESTMESSAGE;
}

