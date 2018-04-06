#include "GuildBulletinSetErrorMessage.h"

void GuildBulletinSetErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildBulletinSetErrorMessage(param1);
}

void GuildBulletinSetErrorMessage::serializeAs_GuildBulletinSetErrorMessage(Writer *param1)
{
  SocialNoticeSetErrorMessage::serializeAs_SocialNoticeSetErrorMessage(param1);
}

void GuildBulletinSetErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildBulletinSetErrorMessage(param1);
}

void GuildBulletinSetErrorMessage::deserializeAs_GuildBulletinSetErrorMessage(Reader *param1)
{
  SocialNoticeSetErrorMessage::deserialize(param1);
}

GuildBulletinSetErrorMessage::GuildBulletinSetErrorMessage()
{
  m_type = MessageEnum::GUILDBULLETINSETERRORMESSAGE;
}

