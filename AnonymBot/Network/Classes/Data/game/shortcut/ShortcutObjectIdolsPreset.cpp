#include "ShortcutObjectIdolsPreset.h"

void ShortcutObjectIdolsPreset::serialize(Writer *param1)
{
  this->serializeAs_ShortcutObjectIdolsPreset(param1);
}

void ShortcutObjectIdolsPreset::serializeAs_ShortcutObjectIdolsPreset(Writer *param1)
{
  ShortcutObject::serializeAs_ShortcutObject(param1);
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - ShortcutObjectIdolsPreset -"<<"Forbidden value (" << this->presetId << ") on element presetId.";
  }
  else
  {
    param1->writeByte(this->presetId);
    return;
  }
}

void ShortcutObjectIdolsPreset::deserialize(Reader *param1)
{
  this->deserializeAs_ShortcutObjectIdolsPreset(param1);
}

void ShortcutObjectIdolsPreset::deserializeAs_ShortcutObjectIdolsPreset(Reader *param1)
{
  ShortcutObject::deserialize(param1);
  this->presetId = param1->readByte();
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - ShortcutObjectIdolsPreset -"<<"Forbidden value (" << this->presetId << ") on element of ShortcutObjectIdolsPreset.presetId.";
  }
  else
  {
    return;
  }
}

ShortcutObjectIdolsPreset::ShortcutObjectIdolsPreset()
{
  m_types<<ClassEnum::SHORTCUTOBJECTIDOLSPRESET;
}

bool ShortcutObjectIdolsPreset::operator==(const ShortcutObjectIdolsPreset &compared)
{
  if(presetId == compared.presetId)
  return true;
  
  return false;
}

