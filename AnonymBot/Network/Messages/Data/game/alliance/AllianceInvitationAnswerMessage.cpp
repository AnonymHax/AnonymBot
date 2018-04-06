#include "AllianceInvitationAnswerMessage.h"

void AllianceInvitationAnswerMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceInvitationAnswerMessage(param1);
}

void AllianceInvitationAnswerMessage::serializeAs_AllianceInvitationAnswerMessage(Writer *param1)
{
  param1->writeBool(this->accept);
}

void AllianceInvitationAnswerMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceInvitationAnswerMessage(param1);
}

void AllianceInvitationAnswerMessage::deserializeAs_AllianceInvitationAnswerMessage(Reader *param1)
{
  this->accept = param1->readBool();
}

AllianceInvitationAnswerMessage::AllianceInvitationAnswerMessage()
{
  m_type = MessageEnum::ALLIANCEINVITATIONANSWERMESSAGE;
}

