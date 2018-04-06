#include "PresetIconData.h"

int PresetIconData::getId() const
{
  return m_id;
}

int PresetIconData::getOrder() const
{
  return m_order;
}

void PresetIconData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "order")
        m_order = readInt(field->getValue());
    
  }
}

