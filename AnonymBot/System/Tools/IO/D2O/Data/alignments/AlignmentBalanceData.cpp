#include "AlignmentBalanceData.h"

int AlignmentBalanceData::getId() const
{
  return m_id;
}

int AlignmentBalanceData::getStartValue() const
{
  return m_startValue;
}

int AlignmentBalanceData::getEndValue() const
{
  return m_endValue;
}

uint AlignmentBalanceData::getNameId() const
{
  return m_nameId;
}

uint AlignmentBalanceData::getDescriptionId() const
{
  return m_descriptionId;
}

QString AlignmentBalanceData::getName() const
{
  return m_I18n->getText(m_nameId);
}

QString AlignmentBalanceData::getDescription() const
{
  return m_I18n->getText(m_descriptionId);
}

void AlignmentBalanceData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "startValue")
        m_startValue = readInt(field->getValue());
    
    else if(field->getName() == "endValue")
        m_endValue = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "descriptionId")
        m_descriptionId = readUInt(field->getValue());
    
  }
}

