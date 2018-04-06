#include "PointOfInterestData.h"

uint PointOfInterestData::getId() const
{
  return m_id;
}

uint PointOfInterestData::getNameId() const
{
  return m_nameId;
}

uint PointOfInterestData::getCategoryId() const
{
  return m_categoryId;
}

QString PointOfInterestData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void PointOfInterestData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "categoryId")
        m_categoryId = readUInt(field->getValue());
    
  }
}

