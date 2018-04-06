#include "AllianceBulletinSetRequestMessage.h"

void AllianceBulletinSetRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceBulletinSetRequestMessage(param1);
}

void AllianceBulletinSetRequestMessage::serializeAs_AllianceBulletinSetRequestMessage(Writer *param1)
{
  SocialNoticeSetRequestMessage::serializeAs_SocialNoticeSetRequestMessage(param1);
  param1->writeUTF(this->content);
  param1->writeBool(this->notifyMembers);
}

void AllianceBulletinSetRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceBulletinSetRequestMessage(param1);
}

void AllianceBulletinSetRequestMessage::deserializeAs_AllianceBulletinSetRequestMessage(Reader *param1)
{
  SocialNoticeSetRequestMessage::deserialize(param1);
  this->content = param1->readUTF();
  this->notifyMembers = param1->readBool();
}

AllianceBulletinSetRequestMessage::AllianceBulletinSetRequestMessage()
{
  m_type = MessageEnum::ALLIANCEBULLETINSETREQUESTMESSAGE;
}

