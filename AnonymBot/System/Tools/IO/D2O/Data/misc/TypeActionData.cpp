#include "TypeActionData.h"

int TypeActionData::getId() const
{
  return m_id;
}

QString TypeActionData::getElementName() const
{
  return m_elementName;
}

int TypeActionData::getElementId() const
{
  return m_elementId;
}

void TypeActionData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "elementName")
        m_elementName = readUTF(field->getValue());
    
    else if(field->getName() == "elementId")
        m_elementId = readInt(field->getValue());
    
  }
}

