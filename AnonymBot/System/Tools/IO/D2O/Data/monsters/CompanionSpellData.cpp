#include "CompanionSpellData.h"

int CompanionSpellData::getId() const
{
  return m_id;
}

int CompanionSpellData::getSpellId() const
{
  return m_spellId;
}

int CompanionSpellData::getCompanionId() const
{
  return m_companionId;
}

QString CompanionSpellData::getGradeByLevel() const
{
  return m_gradeByLevel;
}

void CompanionSpellData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "spellId")
        m_spellId = readInt(field->getValue());
    
    else if(field->getName() == "companionId")
        m_companionId = readInt(field->getValue());
    
    else if(field->getName() == "gradeByLevel")
        m_gradeByLevel = readUTF(field->getValue());
    
  }
}

