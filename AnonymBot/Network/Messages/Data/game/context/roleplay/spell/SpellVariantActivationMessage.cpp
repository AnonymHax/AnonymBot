#include "SpellVariantActivationMessage.h"

void SpellVariantActivationMessage::serialize(Writer *param1)
{
  this->serializeAs_SpellVariantActivationMessage(param1);
}

void SpellVariantActivationMessage::serializeAs_SpellVariantActivationMessage(Writer *param1)
{
  param1->writeBool(this->result);
  if(this->activatedSpellId < 0)
  {
    qDebug()<<"ERREUR - SpellVariantActivationMessage -"<<"Forbidden value (" << this->activatedSpellId << ") on element activatedSpellId.";
  }
  else
  {
    param1->writeVarShort((int)this->activatedSpellId);
    if(this->deactivatedSpellId < 0)
    {
      qDebug()<<"ERREUR - SpellVariantActivationMessage -"<<"Forbidden value (" << this->deactivatedSpellId << ") on element deactivatedSpellId.";
    }
    else
    {
      param1->writeVarShort((int)this->deactivatedSpellId);
      return;
    }
  }
}

void SpellVariantActivationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SpellVariantActivationMessage(param1);
}

void SpellVariantActivationMessage::deserializeAs_SpellVariantActivationMessage(Reader *param1)
{
  this->result = param1->readBool();
  this->activatedSpellId = param1->readVarUhShort();
  if(this->activatedSpellId < 0)
  {
    qDebug()<<"ERREUR - SpellVariantActivationMessage -"<<"Forbidden value (" << this->activatedSpellId << ") on element of SpellVariantActivationMessage.activatedSpellId.";
  }
  else
  {
    this->deactivatedSpellId = param1->readVarUhShort();
    if(this->deactivatedSpellId < 0)
    {
      qDebug()<<"ERREUR - SpellVariantActivationMessage -"<<"Forbidden value (" << this->deactivatedSpellId << ") on element of SpellVariantActivationMessage.deactivatedSpellId.";
    }
    else
    {
      return;
    }
  }
}

SpellVariantActivationMessage::SpellVariantActivationMessage()
{
  m_type = MessageEnum::SPELLVARIANTACTIVATIONMESSAGE;
}

