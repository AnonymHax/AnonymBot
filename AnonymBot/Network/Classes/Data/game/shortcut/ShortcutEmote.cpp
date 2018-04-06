#include "ShortcutEmote.h"

void ShortcutEmote::serialize(Writer *param1)
{
  this->serializeAs_ShortcutEmote(param1);
}

void ShortcutEmote::serializeAs_ShortcutEmote(Writer *param1)
{
  Shortcut::serializeAs_Shortcut(param1);
  if(this->emoteId < 0 || this->emoteId > 255)
  {
    qDebug()<<"ERREUR - ShortcutEmote -"<<"Forbidden value (" << this->emoteId << ") on element emoteId.";
  }
  else
  {
    param1->writeByte(this->emoteId);
    return;
  }
}

void ShortcutEmote::deserialize(Reader *param1)
{
  this->deserializeAs_ShortcutEmote(param1);
}

void ShortcutEmote::deserializeAs_ShortcutEmote(Reader *param1)
{
  Shortcut::deserialize(param1);
  this->emoteId = param1->readUByte();
  if(this->emoteId < 0 || this->emoteId > 255)
  {
    qDebug()<<"ERREUR - ShortcutEmote -"<<"Forbidden value (" << this->emoteId << ") on element of ShortcutEmote.emoteId.";
  }
  else
  {
    return;
  }
}

ShortcutEmote::ShortcutEmote()
{
  m_types<<ClassEnum::SHORTCUTEMOTE;
}

bool ShortcutEmote::operator==(const ShortcutEmote &compared)
{
  if(emoteId == compared.emoteId)
  return true;
  
  return false;
}

