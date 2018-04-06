#include "SpellModifyRequestMessage.h"

void SpellModifyRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_SpellModifyRequestMessage(param1);
}

void SpellModifyRequestMessage::serializeAs_SpellModifyRequestMessage(Writer *param1)
{
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - SpellModifyRequestMessage -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  else
  {
    param1->writeVarShort((int)this->spellId);
    if(this->spellLevel < 1 || this->spellLevel > 200)
    {
      qDebug()<<"ERREUR - SpellModifyRequestMessage -"<<"Forbidden value (" << this->spellLevel << ") on element spellLevel.";
    }
    else
    {
      param1->writeShort((short)this->spellLevel);
      return;
    }
  }
}

void SpellModifyRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SpellModifyRequestMessage(param1);
}

void SpellModifyRequestMessage::deserializeAs_SpellModifyRequestMessage(Reader *param1)
{
  this->spellId = param1->readVarUhShort();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - SpellModifyRequestMessage -"<<"Forbidden value (" << this->spellId << ") on element of SpellModifyRequestMessage.spellId.";
  }
  else
  {
    this->spellLevel = param1->readShort();
    if(this->spellLevel < 1 || this->spellLevel > 200)
    {
      qDebug()<<"ERREUR - SpellModifyRequestMessage -"<<"Forbidden value (" << this->spellLevel << ") on element of SpellModifyRequestMessage.spellLevel.";
    }
    else
    {
      return;
    }
  }
}

SpellModifyRequestMessage::SpellModifyRequestMessage()
{
  m_type = MessageEnum::SPELLMODIFYREQUESTMESSAGE;
}

