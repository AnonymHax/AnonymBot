#include "ShortcutSpell.h"

void ShortcutSpell::serialize(Writer *param1)
{
  this->serializeAs_ShortcutSpell(param1);
}

void ShortcutSpell::serializeAs_ShortcutSpell(Writer *param1)
{
  Shortcut::serializeAs_Shortcut(param1);
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - ShortcutSpell -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  else
  {
    param1->writeVarShort((int)this->spellId);
    return;
  }
}

void ShortcutSpell::deserialize(Reader *param1)
{
  this->deserializeAs_ShortcutSpell(param1);
}

void ShortcutSpell::deserializeAs_ShortcutSpell(Reader *param1)
{
  Shortcut::deserialize(param1);
  this->spellId = param1->readVarUhShort();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - ShortcutSpell -"<<"Forbidden value (" << this->spellId << ") on element of ShortcutSpell.spellId.";
  }
  else
  {
    return;
  }
}

ShortcutSpell::ShortcutSpell()
{
  m_types<<ClassEnum::SHORTCUTSPELL;
}

bool ShortcutSpell::operator==(const ShortcutSpell &compared)
{
  if(spellId == compared.spellId)
  return true;
  
  return false;
}

