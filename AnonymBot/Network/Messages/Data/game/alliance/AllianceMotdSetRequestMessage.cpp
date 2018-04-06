#include "AllianceMotdSetRequestMessage.h"

void AllianceMotdSetRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceMotdSetRequestMessage(param1);
}

void AllianceMotdSetRequestMessage::serializeAs_AllianceMotdSetRequestMessage(Writer *param1)
{
  SocialNoticeSetRequestMessage::serializeAs_SocialNoticeSetRequestMessage(param1);
  param1->writeUTF(this->content);
}

void AllianceMotdSetRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceMotdSetRequestMessage(param1);
}

void AllianceMotdSetRequestMessage::deserializeAs_AllianceMotdSetRequestMessage(Reader *param1)
{
  SocialNoticeSetRequestMessage::deserialize(param1);
  this->content = param1->readUTF();
}

AllianceMotdSetRequestMessage::AllianceMotdSetRequestMessage()
{
  m_type = MessageEnum::ALLIANCEMOTDSETREQUESTMESSAGE;
}

