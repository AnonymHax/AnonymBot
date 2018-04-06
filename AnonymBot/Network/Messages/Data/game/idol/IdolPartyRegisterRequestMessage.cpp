#include "IdolPartyRegisterRequestMessage.h"

void IdolPartyRegisterRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_IdolPartyRegisterRequestMessage(param1);
}

void IdolPartyRegisterRequestMessage::serializeAs_IdolPartyRegisterRequestMessage(Writer *param1)
{
  param1->writeBool(this->m_register);
}

void IdolPartyRegisterRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IdolPartyRegisterRequestMessage(param1);
}

void IdolPartyRegisterRequestMessage::deserializeAs_IdolPartyRegisterRequestMessage(Reader *param1)
{
  this->m_register = param1->readBool();
}

IdolPartyRegisterRequestMessage::IdolPartyRegisterRequestMessage()
{
  m_type = MessageEnum::IDOLPARTYREGISTERREQUESTMESSAGE;
}

