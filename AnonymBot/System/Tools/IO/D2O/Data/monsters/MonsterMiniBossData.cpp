#include "MonsterMiniBossData.h"

int MonsterMiniBossData::getId() const
{
  return m_id;
}

int MonsterMiniBossData::getMonsterReplacingId() const
{
  return m_monsterReplacingId;
}

void MonsterMiniBossData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "monsterReplacingId")
        m_monsterReplacingId = readInt(field->getValue());
    
  }
}

