#include "TeleportBuddiesAnswerMessage.h"

void TeleportBuddiesAnswerMessage::serialize(Writer *param1)
{
  this->serializeAs_TeleportBuddiesAnswerMessage(param1);
}

void TeleportBuddiesAnswerMessage::serializeAs_TeleportBuddiesAnswerMessage(Writer *param1)
{
  param1->writeBool(this->accept);
}

void TeleportBuddiesAnswerMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TeleportBuddiesAnswerMessage(param1);
}

void TeleportBuddiesAnswerMessage::deserializeAs_TeleportBuddiesAnswerMessage(Reader *param1)
{
  this->accept = param1->readBool();
}

TeleportBuddiesAnswerMessage::TeleportBuddiesAnswerMessage()
{
  m_type = MessageEnum::TELEPORTBUDDIESANSWERMESSAGE;
}

