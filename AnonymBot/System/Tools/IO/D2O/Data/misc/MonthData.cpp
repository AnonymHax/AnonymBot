#include "MonthData.h"

int MonthData::getId() const
{
  return m_id;
}

uint MonthData::getNameId() const
{
  return m_nameId;
}

QString MonthData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void MonthData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
  }
}

