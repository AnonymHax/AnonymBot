#include "GuildCharacsUpgradeRequestMessage.h"

void GuildCharacsUpgradeRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildCharacsUpgradeRequestMessage(param1);
}

void GuildCharacsUpgradeRequestMessage::serializeAs_GuildCharacsUpgradeRequestMessage(Writer *param1)
{
  param1->writeByte(this->charaTypeTarget);
}

void GuildCharacsUpgradeRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildCharacsUpgradeRequestMessage(param1);
}

void GuildCharacsUpgradeRequestMessage::deserializeAs_GuildCharacsUpgradeRequestMessage(Reader *param1)
{
  this->charaTypeTarget = param1->readByte();
  if(this->charaTypeTarget < 0)
  {
    qDebug()<<"ERREUR - GuildCharacsUpgradeRequestMessage -"<<"Forbidden value (" << this->charaTypeTarget << ") on element of GuildCharacsUpgradeRequestMessage.charaTypeTarget.";
  }
  else
  {
    return;
  }
}

GuildCharacsUpgradeRequestMessage::GuildCharacsUpgradeRequestMessage()
{
  m_type = MessageEnum::GUILDCHARACSUPGRADEREQUESTMESSAGE;
}

