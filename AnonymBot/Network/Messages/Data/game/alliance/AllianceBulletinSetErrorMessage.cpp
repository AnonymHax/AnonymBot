#include "AllianceBulletinSetErrorMessage.h"

void AllianceBulletinSetErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceBulletinSetErrorMessage(param1);
}

void AllianceBulletinSetErrorMessage::serializeAs_AllianceBulletinSetErrorMessage(Writer *param1)
{
  SocialNoticeSetErrorMessage::serializeAs_SocialNoticeSetErrorMessage(param1);
}

void AllianceBulletinSetErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceBulletinSetErrorMessage(param1);
}

void AllianceBulletinSetErrorMessage::deserializeAs_AllianceBulletinSetErrorMessage(Reader *param1)
{
  SocialNoticeSetErrorMessage::deserialize(param1);
}

AllianceBulletinSetErrorMessage::AllianceBulletinSetErrorMessage()
{
  m_type = MessageEnum::ALLIANCEBULLETINSETERRORMESSAGE;
}

