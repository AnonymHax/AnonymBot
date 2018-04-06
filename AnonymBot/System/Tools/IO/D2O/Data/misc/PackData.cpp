#include "PackData.h"

int PackData::getId() const
{
  return m_id;
}

QString PackData::getName() const
{
  return m_name;
}

bool PackData::getHasSubAreas() const
{
  return m_hasSubAreas;
}

void PackData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "name")
        m_name = readUTF(field->getValue());
    
    else if(field->getName() == "hasSubAreas")
        m_hasSubAreas = readBool(field->getValue());
    
  }
}

