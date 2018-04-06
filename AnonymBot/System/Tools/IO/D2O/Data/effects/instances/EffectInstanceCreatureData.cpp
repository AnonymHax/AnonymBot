#include "EffectInstanceCreatureData.h"

uint EffectInstanceCreatureData::getMonsterFamilyId() const
{
  return m_monsterFamilyId;
}

void EffectInstanceCreatureData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  EffectInstanceData::loadData(fields, I18n);
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "monsterFamilyId")
        m_monsterFamilyId = readUInt(field->getValue());
    
  }
}

