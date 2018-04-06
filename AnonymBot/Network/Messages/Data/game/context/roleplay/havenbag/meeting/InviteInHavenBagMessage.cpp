#include "InviteInHavenBagMessage.h"

void InviteInHavenBagMessage::serialize(Writer *param1)
{
  this->serializeAs_InviteInHavenBagMessage(param1);
}

void InviteInHavenBagMessage::serializeAs_InviteInHavenBagMessage(Writer *param1)
{
  this->guestInformations.serializeAs_CharacterMinimalInformations(param1);
  param1->writeBool(this->accept);
}

void InviteInHavenBagMessage::deserialize(Reader *param1)
{
  this->deserializeAs_InviteInHavenBagMessage(param1);
}

void InviteInHavenBagMessage::deserializeAs_InviteInHavenBagMessage(Reader *param1)
{
  this->guestInformations = CharacterMinimalInformations();
  this->guestInformations.deserialize(param1);
  this->accept = param1->readBool();
}

InviteInHavenBagMessage::InviteInHavenBagMessage()
{
  m_type = MessageEnum::INVITEINHAVENBAGMESSAGE;
}

