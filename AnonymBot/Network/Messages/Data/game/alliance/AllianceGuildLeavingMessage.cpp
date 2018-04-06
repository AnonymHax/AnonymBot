#include "AllianceGuildLeavingMessage.h"

void AllianceGuildLeavingMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceGuildLeavingMessage(param1);
}

void AllianceGuildLeavingMessage::serializeAs_AllianceGuildLeavingMessage(Writer *param1)
{
  param1->writeBool(this->kicked);
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - AllianceGuildLeavingMessage -"<<"Forbidden value (" << this->guildId << ") on element guildId.";
  }
  else
  {
    param1->writeVarInt((int)this->guildId);
    return;
  }
}

void AllianceGuildLeavingMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceGuildLeavingMessage(param1);
}

void AllianceGuildLeavingMessage::deserializeAs_AllianceGuildLeavingMessage(Reader *param1)
{
  this->kicked = param1->readBool();
  this->guildId = param1->readVarUhInt();
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - AllianceGuildLeavingMessage -"<<"Forbidden value (" << this->guildId << ") on element of AllianceGuildLeavingMessage.guildId.";
  }
  else
  {
    return;
  }
}

AllianceGuildLeavingMessage::AllianceGuildLeavingMessage()
{
  m_type = MessageEnum::ALLIANCEGUILDLEAVINGMESSAGE;
}

