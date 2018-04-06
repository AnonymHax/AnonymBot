#include "AllianceChangeGuildRightsMessage.h"

void AllianceChangeGuildRightsMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceChangeGuildRightsMessage(param1);
}

void AllianceChangeGuildRightsMessage::serializeAs_AllianceChangeGuildRightsMessage(Writer *param1)
{
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - AllianceChangeGuildRightsMessage -"<<"Forbidden value (" << this->guildId << ") on element guildId.";
  }
  else
  {
    param1->writeVarInt((int)this->guildId);
    if(this->rights < 0)
    {
      qDebug()<<"ERREUR - AllianceChangeGuildRightsMessage -"<<"Forbidden value (" << this->rights << ") on element rights.";
    }
    else
    {
      param1->writeByte(this->rights);
      return;
    }
  }
}

void AllianceChangeGuildRightsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceChangeGuildRightsMessage(param1);
}

void AllianceChangeGuildRightsMessage::deserializeAs_AllianceChangeGuildRightsMessage(Reader *param1)
{
  this->guildId = param1->readVarUhInt();
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - AllianceChangeGuildRightsMessage -"<<"Forbidden value (" << this->guildId << ") on element of AllianceChangeGuildRightsMessage.guildId.";
  }
  else
  {
    this->rights = param1->readByte();
    if(this->rights < 0)
    {
      qDebug()<<"ERREUR - AllianceChangeGuildRightsMessage -"<<"Forbidden value (" << this->rights << ") on element of AllianceChangeGuildRightsMessage.rights.";
    }
    else
    {
      return;
    }
  }
}

AllianceChangeGuildRightsMessage::AllianceChangeGuildRightsMessage()
{
  m_type = MessageEnum::ALLIANCECHANGEGUILDRIGHTSMESSAGE;
}

