#include "ShortcutSmiley.h"

void ShortcutSmiley::serialize(Writer *param1)
{
  this->serializeAs_ShortcutSmiley(param1);
}

void ShortcutSmiley::serializeAs_ShortcutSmiley(Writer *param1)
{
  Shortcut::serializeAs_Shortcut(param1);
  if(this->smileyId < 0)
  {
    qDebug()<<"ERREUR - ShortcutSmiley -"<<"Forbidden value (" << this->smileyId << ") on element smileyId.";
  }
  else
  {
    param1->writeVarShort((int)this->smileyId);
    return;
  }
}

void ShortcutSmiley::deserialize(Reader *param1)
{
  this->deserializeAs_ShortcutSmiley(param1);
}

void ShortcutSmiley::deserializeAs_ShortcutSmiley(Reader *param1)
{
  Shortcut::deserialize(param1);
  this->smileyId = param1->readVarUhShort();
  if(this->smileyId < 0)
  {
    qDebug()<<"ERREUR - ShortcutSmiley -"<<"Forbidden value (" << this->smileyId << ") on element of ShortcutSmiley.smileyId.";
  }
  else
  {
    return;
  }
}

ShortcutSmiley::ShortcutSmiley()
{
  m_types<<ClassEnum::SHORTCUTSMILEY;
}

bool ShortcutSmiley::operator==(const ShortcutSmiley &compared)
{
  if(smileyId == compared.smileyId)
  return true;
  
  return false;
}

