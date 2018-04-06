#include "SpellItemBoostMessage.h"

void SpellItemBoostMessage::serialize(Writer *param1)
{
  this->serializeAs_SpellItemBoostMessage(param1);
}

void SpellItemBoostMessage::serializeAs_SpellItemBoostMessage(Writer *param1)
{
  if(this->statId < 0)
  {
    qDebug()<<"ERREUR - SpellItemBoostMessage -"<<"Forbidden value (" << this->statId << ") on element statId.";
  }
  else
  {
    param1->writeVarInt((int)this->statId);
    if(this->spellId < 0)
    {
      qDebug()<<"ERREUR - SpellItemBoostMessage -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
    }
    else
    {
      param1->writeVarShort((int)this->spellId);
      param1->writeVarShort((int)this->value);
      return;
    }
  }
}

void SpellItemBoostMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SpellItemBoostMessage(param1);
}

void SpellItemBoostMessage::deserializeAs_SpellItemBoostMessage(Reader *param1)
{
  this->statId = param1->readVarUhInt();
  if(this->statId < 0)
  {
    qDebug()<<"ERREUR - SpellItemBoostMessage -"<<"Forbidden value (" << this->statId << ") on element of SpellItemBoostMessage.statId.";
  }
  else
  {
    this->spellId = param1->readVarUhShort();
    if(this->spellId < 0)
    {
      qDebug()<<"ERREUR - SpellItemBoostMessage -"<<"Forbidden value (" << this->spellId << ") on element of SpellItemBoostMessage.spellId.";
    }
    else
    {
      this->value = param1->readVarShort();
      return;
    }
  }
}

SpellItemBoostMessage::SpellItemBoostMessage()
{
  m_type = MessageEnum::SPELLITEMBOOSTMESSAGE;
}

