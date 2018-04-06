#include "GuildBulletinSetRequestMessage.h"

void GuildBulletinSetRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildBulletinSetRequestMessage(param1);
}

void GuildBulletinSetRequestMessage::serializeAs_GuildBulletinSetRequestMessage(Writer *param1)
{
  SocialNoticeSetRequestMessage::serializeAs_SocialNoticeSetRequestMessage(param1);
  param1->writeUTF(this->content);
  param1->writeBool(this->notifyMembers);
}

void GuildBulletinSetRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildBulletinSetRequestMessage(param1);
}

void GuildBulletinSetRequestMessage::deserializeAs_GuildBulletinSetRequestMessage(Reader *param1)
{
  SocialNoticeSetRequestMessage::deserialize(param1);
  this->content = param1->readUTF();
  this->notifyMembers = param1->readBool();
}

GuildBulletinSetRequestMessage::GuildBulletinSetRequestMessage()
{
  m_type = MessageEnum::GUILDBULLETINSETREQUESTMESSAGE;
}

