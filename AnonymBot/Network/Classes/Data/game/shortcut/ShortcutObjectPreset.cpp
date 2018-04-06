#include "ShortcutObjectPreset.h"

void ShortcutObjectPreset::serialize(Writer *param1)
{
  this->serializeAs_ShortcutObjectPreset(param1);
}

void ShortcutObjectPreset::serializeAs_ShortcutObjectPreset(Writer *param1)
{
  ShortcutObject::serializeAs_ShortcutObject(param1);
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - ShortcutObjectPreset -"<<"Forbidden value (" << this->presetId << ") on element presetId.";
  }
  else
  {
    param1->writeByte(this->presetId);
    return;
  }
}

void ShortcutObjectPreset::deserialize(Reader *param1)
{
  this->deserializeAs_ShortcutObjectPreset(param1);
}

void ShortcutObjectPreset::deserializeAs_ShortcutObjectPreset(Reader *param1)
{
  ShortcutObject::deserialize(param1);
  this->presetId = param1->readByte();
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - ShortcutObjectPreset -"<<"Forbidden value (" << this->presetId << ") on element of ShortcutObjectPreset.presetId.";
  }
  else
  {
    return;
  }
}

ShortcutObjectPreset::ShortcutObjectPreset()
{
  m_types<<ClassEnum::SHORTCUTOBJECTPRESET;
}

bool ShortcutObjectPreset::operator==(const ShortcutObjectPreset &compared)
{
  if(presetId == compared.presetId)
  return true;
  
  return false;
}

