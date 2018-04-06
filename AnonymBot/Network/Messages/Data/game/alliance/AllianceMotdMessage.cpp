#include "AllianceMotdMessage.h"

void AllianceMotdMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceMotdMessage(param1);
}

void AllianceMotdMessage::serializeAs_AllianceMotdMessage(Writer *param1)
{
  SocialNoticeMessage::serializeAs_SocialNoticeMessage(param1);
}

void AllianceMotdMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceMotdMessage(param1);
}

void AllianceMotdMessage::deserializeAs_AllianceMotdMessage(Reader *param1)
{
  SocialNoticeMessage::deserialize(param1);
}

AllianceMotdMessage::AllianceMotdMessage()
{
  m_type = MessageEnum::ALLIANCEMOTDMESSAGE;
}

