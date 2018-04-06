#include "GuildLevelUpMessage.h"

void GuildLevelUpMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildLevelUpMessage(param1);
}

void GuildLevelUpMessage::serializeAs_GuildLevelUpMessage(Writer *param1)
{
  if(this->newLevel < 2 || this->newLevel > 200)
  {
    qDebug()<<"ERREUR - GuildLevelUpMessage -"<<"Forbidden value (" << this->newLevel << ") on element newLevel.";
  }
  else
  {
    param1->writeByte(this->newLevel);
    return;
  }
}

void GuildLevelUpMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildLevelUpMessage(param1);
}

void GuildLevelUpMessage::deserializeAs_GuildLevelUpMessage(Reader *param1)
{
  this->newLevel = param1->readUByte();
  if(this->newLevel < 2 || this->newLevel > 200)
  {
    qDebug()<<"ERREUR - GuildLevelUpMessage -"<<"Forbidden value (" << this->newLevel << ") on element of GuildLevelUpMessage.newLevel.";
  }
  else
  {
    return;
  }
}

GuildLevelUpMessage::GuildLevelUpMessage()
{
  m_type = MessageEnum::GUILDLEVELUPMESSAGE;
}

