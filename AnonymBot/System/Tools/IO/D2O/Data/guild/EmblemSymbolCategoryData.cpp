#include "EmblemSymbolCategoryData.h"

int EmblemSymbolCategoryData::getId() const
{
  return m_id;
}

uint EmblemSymbolCategoryData::getNameId() const
{
  return m_nameId;
}

QString EmblemSymbolCategoryData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void EmblemSymbolCategoryData::loadData(const QList<Field*> &fields, I18nFile *I18n)
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

