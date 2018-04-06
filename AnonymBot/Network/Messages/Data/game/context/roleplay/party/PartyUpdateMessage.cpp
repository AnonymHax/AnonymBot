#include "PartyUpdateMessage.h"

void PartyUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_PartyUpdateMessage(param1);
}

void PartyUpdateMessage::serializeAs_PartyUpdateMessage(Writer *param1)
{
  AbstractPartyEventMessage::serializeAs_AbstractPartyEventMessage(param1);
  param1->writeShort((short)this->memberInformations->getTypes().last());
  this->memberInformations->serialize(param1);
}

void PartyUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartyUpdateMessage(param1);
}

void PartyUpdateMessage::deserializeAs_PartyUpdateMessage(Reader *param1)
{
  AbstractPartyEventMessage::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  this->memberInformations = qSharedPointerCast<PartyMemberInformations>(ClassManagerSingleton::get()->getClass(_loc2_));
  this->memberInformations->deserialize(param1);
}

PartyUpdateMessage::PartyUpdateMessage()
{
  m_type = MessageEnum::PARTYUPDATEMESSAGE;
}

