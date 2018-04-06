#include "AllianceMotdSetErrorMessage.h"

void AllianceMotdSetErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceMotdSetErrorMessage(param1);
}

void AllianceMotdSetErrorMessage::serializeAs_AllianceMotdSetErrorMessage(Writer *param1)
{
  SocialNoticeSetErrorMessage::serializeAs_SocialNoticeSetErrorMessage(param1);
}

void AllianceMotdSetErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceMotdSetErrorMessage(param1);
}

void AllianceMotdSetErrorMessage::deserializeAs_AllianceMotdSetErrorMessage(Reader *param1)
{
  SocialNoticeSetErrorMessage::deserialize(param1);
}

AllianceMotdSetErrorMessage::AllianceMotdSetErrorMessage()
{
  m_type = MessageEnum::ALLIANCEMOTDSETERRORMESSAGE;
}

