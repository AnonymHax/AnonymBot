#include "GuildInvitationAnswerMessage.h"

void GuildInvitationAnswerMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildInvitationAnswerMessage(param1);
}

void GuildInvitationAnswerMessage::serializeAs_GuildInvitationAnswerMessage(Writer *param1)
{
  param1->writeBool(this->accept);
}

void GuildInvitationAnswerMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildInvitationAnswerMessage(param1);
}

void GuildInvitationAnswerMessage::deserializeAs_GuildInvitationAnswerMessage(Reader *param1)
{
  this->accept = param1->readBool();
}

GuildInvitationAnswerMessage::GuildInvitationAnswerMessage()
{
  m_type = MessageEnum::GUILDINVITATIONANSWERMESSAGE;
}

