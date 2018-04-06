#include "InviteInHavenBagClosedMessage.h"

void InviteInHavenBagClosedMessage::serialize(Writer *param1)
{
  this->serializeAs_InviteInHavenBagClosedMessage(param1);
}

void InviteInHavenBagClosedMessage::serializeAs_InviteInHavenBagClosedMessage(Writer *param1)
{
  this->hostInformations.serializeAs_CharacterMinimalInformations(param1);
}

void InviteInHavenBagClosedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_InviteInHavenBagClosedMessage(param1);
}

void InviteInHavenBagClosedMessage::deserializeAs_InviteInHavenBagClosedMessage(Reader *param1)
{
  this->hostInformations = CharacterMinimalInformations();
  this->hostInformations.deserialize(param1);
}

InviteInHavenBagClosedMessage::InviteInHavenBagClosedMessage()
{
  m_type = MessageEnum::INVITEINHAVENBAGCLOSEDMESSAGE;
}

