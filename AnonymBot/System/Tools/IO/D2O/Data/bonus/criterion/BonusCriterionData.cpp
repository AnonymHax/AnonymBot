#include "BonusCriterionData.h"

int BonusCriterionData::getId() const
{
  return m_id;
}

uint BonusCriterionData::getType() const
{
  return m_type;
}

int BonusCriterionData::getValue() const
{
  return m_value;
}

void BonusCriterionData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "type")
        m_type = readUInt(field->getValue());
    
    else if(field->getName() == "value")
        m_value = readInt(field->getValue());
    
  }
}

