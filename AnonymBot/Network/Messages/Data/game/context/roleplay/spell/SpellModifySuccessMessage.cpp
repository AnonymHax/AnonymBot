#include "SpellModifySuccessMessage.h"

void SpellModifySuccessMessage::serialize(Writer *param1)
{
  this->serializeAs_SpellModifySuccessMessage(param1);
}

void SpellModifySuccessMessage::serializeAs_SpellModifySuccessMessage(Writer *param1)
{
  param1->writeInt((int)this->spellId);
  if(this->spellLevel < 1 || this->spellLevel > 200)
  {
    qDebug()<<"ERREUR - SpellModifySuccessMessage -"<<"Forbidden value (" << this->spellLevel << ") on element spellLevel.";
  }
  else
  {
    param1->writeShort((short)this->spellLevel);
    return;
  }
}

void SpellModifySuccessMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SpellModifySuccessMessage(param1);
}

void SpellModifySuccessMessage::deserializeAs_SpellModifySuccessMessage(Reader *param1)
{
  this->spellId = param1->readInt();
  this->spellLevel = param1->readShort();
  if(this->spellLevel < 1 || this->spellLevel > 200)
  {
    qDebug()<<"ERREUR - SpellModifySuccessMessage -"<<"Forbidden value (" << this->spellLevel << ") on element of SpellModifySuccessMessage.spellLevel.";
  }
  else
  {
    return;
  }
}

SpellModifySuccessMessage::SpellModifySuccessMessage()
{
  m_type = MessageEnum::SPELLMODIFYSUCCESSMESSAGE;
}

