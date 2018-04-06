#include "PhoenixData.h"

uint PhoenixData::getMapId() const
{
  return m_mapId;
}

void PhoenixData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "mapId")
        m_mapId = readUInt(field->getValue());
    
  }
}

