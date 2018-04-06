#include "GuildFactsErrorMessage.h"

void GuildFactsErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildFactsErrorMessage(param1);
}

void GuildFactsErrorMessage::serializeAs_GuildFactsErrorMessage(Writer *param1)
{
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - GuildFactsErrorMessage -"<<"Forbidden value (" << this->guildId << ") on element guildId.";
  }
  else
  {
    param1->writeVarInt((int)this->guildId);
    return;
  }
}

void GuildFactsErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildFactsErrorMessage(param1);
}

void GuildFactsErrorMessage::deserializeAs_GuildFactsErrorMessage(Reader *param1)
{
  this->guildId = param1->readVarUhInt();
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - GuildFactsErrorMessage -"<<"Forbidden value (" << this->guildId << ") on element of GuildFactsErrorMessage.guildId.";
  }
  else
  {
    return;
  }
}

GuildFactsErrorMessage::GuildFactsErrorMessage()
{
  m_type = MessageEnum::GUILDFACTSERRORMESSAGE;
}

