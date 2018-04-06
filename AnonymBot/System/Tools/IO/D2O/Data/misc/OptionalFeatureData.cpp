#include "OptionalFeatureData.h"

int OptionalFeatureData::getId() const
{
  return m_id;
}

QString OptionalFeatureData::getKeyword() const
{
  return m_keyword;
}

void OptionalFeatureData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "keyword")
        m_keyword = readUTF(field->getValue());
    
  }
}

