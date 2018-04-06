#include "InviteInHavenBagOfferMessage.h"

void InviteInHavenBagOfferMessage::serialize(Writer *param1)
{
  this->serializeAs_InviteInHavenBagOfferMessage(param1);
}

void InviteInHavenBagOfferMessage::serializeAs_InviteInHavenBagOfferMessage(Writer *param1)
{
  this->hostInformations.serializeAs_CharacterMinimalInformations(param1);
  param1->writeVarInt((int)this->timeLeftBeforeCancel);
}

void InviteInHavenBagOfferMessage::deserialize(Reader *param1)
{
  this->deserializeAs_InviteInHavenBagOfferMessage(param1);
}

void InviteInHavenBagOfferMessage::deserializeAs_InviteInHavenBagOfferMessage(Reader *param1)
{
  this->hostInformations = CharacterMinimalInformations();
  this->hostInformations.deserialize(param1);
  this->timeLeftBeforeCancel = param1->readVarInt();
}

InviteInHavenBagOfferMessage::InviteInHavenBagOfferMessage()
{
  m_type = MessageEnum::INVITEINHAVENBAGOFFERMESSAGE;
}

