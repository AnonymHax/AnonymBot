#include "AppearanceData.h"

uint AppearanceData::getId() const
{
  return m_id;
}

uint AppearanceData::getType() const
{
  return m_type;
}

QString AppearanceData::getData() const
{
  return m_data;
}

void AppearanceData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "type")
        m_type = readUInt(field->getValue());
    
    else if(field->getName() == "data")
        m_data = readUTF(field->getValue());
    
  }
}

