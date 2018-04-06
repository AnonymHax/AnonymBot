#include "MonsterDropData.h"

uint MonsterDropData::getDropId() const
{
  return m_dropId;
}

int MonsterDropData::getMonsterId() const
{
  return m_monsterId;
}

int MonsterDropData::getObjectId() const
{
  return m_objectId;
}

double MonsterDropData::getPercentDropForGrade1() const
{
  return m_percentDropForGrade1;
}

double MonsterDropData::getPercentDropForGrade2() const
{
  return m_percentDropForGrade2;
}

double MonsterDropData::getPercentDropForGrade3() const
{
  return m_percentDropForGrade3;
}

double MonsterDropData::getPercentDropForGrade4() const
{
  return m_percentDropForGrade4;
}

double MonsterDropData::getPercentDropForGrade5() const
{
  return m_percentDropForGrade5;
}

int MonsterDropData::getCount() const
{
  return m_count;
}

bool MonsterDropData::getHasCriteria() const
{
  return m_hasCriteria;
}

void MonsterDropData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "dropId")
        m_dropId = readUInt(field->getValue());
    
    else if(field->getName() == "monsterId")
        m_monsterId = readInt(field->getValue());
    
    else if(field->getName() == "objectId")
        m_objectId = readInt(field->getValue());
    
    else if(field->getName() == "percentDropForGrade1")
        m_percentDropForGrade1 = readDouble(field->getValue());
    
    else if(field->getName() == "percentDropForGrade2")
        m_percentDropForGrade2 = readDouble(field->getValue());
    
    else if(field->getName() == "percentDropForGrade3")
        m_percentDropForGrade3 = readDouble(field->getValue());
    
    else if(field->getName() == "percentDropForGrade4")
        m_percentDropForGrade4 = readDouble(field->getValue());
    
    else if(field->getName() == "percentDropForGrade5")
        m_percentDropForGrade5 = readDouble(field->getValue());
    
    else if(field->getName() == "count")
        m_count = readInt(field->getValue());
    
    else if(field->getName() == "hasCriteria")
        m_hasCriteria = readBool(field->getValue());
    
  }
}

