#include "SpellVariantActivationRequestMessage.h"

void SpellVariantActivationRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_SpellVariantActivationRequestMessage(param1);
}

void SpellVariantActivationRequestMessage::serializeAs_SpellVariantActivationRequestMessage(Writer *param1)
{
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - SpellVariantActivationRequestMessage -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  else
  {
    param1->writeVarShort((int)this->spellId);
    return;
  }
}

void SpellVariantActivationRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SpellVariantActivationRequestMessage(param1);
}

void SpellVariantActivationRequestMessage::deserializeAs_SpellVariantActivationRequestMessage(Reader *param1)
{
  this->spellId = param1->readVarUhShort();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - SpellVariantActivationRequestMessage -"<<"Forbidden value (" << this->spellId << ") on element of SpellVariantActivationRequestMessage.spellId.";
  }
  else
  {
    return;
  }
}

SpellVariantActivationRequestMessage::SpellVariantActivationRequestMessage()
{
  m_type = MessageEnum::SPELLVARIANTACTIVATIONREQUESTMESSAGE;
}

