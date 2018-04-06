#include "EffectInstanceLadderData.h"

uint EffectInstanceLadderData::getMonsterCount() const
{
  return m_monsterCount;
}

void EffectInstanceLadderData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  EffectInstanceCreatureData::loadData(fields, I18n);
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "monsterCount")
        m_monsterCount = readUInt(field->getValue());
    
  }
}

