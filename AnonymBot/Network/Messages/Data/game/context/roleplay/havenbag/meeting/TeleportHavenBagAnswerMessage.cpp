#include "TeleportHavenBagAnswerMessage.h"

void TeleportHavenBagAnswerMessage::serialize(Writer *param1)
{
  this->serializeAs_TeleportHavenBagAnswerMessage(param1);
}

void TeleportHavenBagAnswerMessage::serializeAs_TeleportHavenBagAnswerMessage(Writer *param1)
{
  param1->writeBool(this->accept);
}

void TeleportHavenBagAnswerMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TeleportHavenBagAnswerMessage(param1);
}

void TeleportHavenBagAnswerMessage::deserializeAs_TeleportHavenBagAnswerMessage(Reader *param1)
{
  this->accept = param1->readBool();
}

TeleportHavenBagAnswerMessage::TeleportHavenBagAnswerMessage()
{
  m_type = MessageEnum::TELEPORTHAVENBAGANSWERMESSAGE;
}

