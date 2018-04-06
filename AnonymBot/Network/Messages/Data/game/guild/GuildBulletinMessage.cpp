#include "GuildBulletinMessage.h"

void GuildBulletinMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildBulletinMessage(param1);
}

void GuildBulletinMessage::serializeAs_GuildBulletinMessage(Writer *param1)
{
  BulletinMessage::serializeAs_BulletinMessage(param1);
}

void GuildBulletinMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildBulletinMessage(param1);
}

void GuildBulletinMessage::deserializeAs_GuildBulletinMessage(Reader *param1)
{
  BulletinMessage::deserialize(param1);
}

GuildBulletinMessage::GuildBulletinMessage()
{
  m_type = MessageEnum::GUILDBULLETINMESSAGE;
}

