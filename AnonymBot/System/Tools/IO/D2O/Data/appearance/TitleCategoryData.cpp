#include "TitleCategoryData.h"

int TitleCategoryData::getId() const
{
  return m_id;
}

uint TitleCategoryData::getNameId() const
{
  return m_nameId;
}

QString TitleCategoryData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void TitleCategoryData::loadData(const QList<Field*> &fields, I18nFile *I18n)
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

