#include "WaypointData.h"

uint WaypointData::getId() const
{
  return m_id;
}

uint WaypointData::getMapId() const
{
  return m_mapId;
}

uint WaypointData::getSubAreaId() const
{
  return m_subAreaId;
}

void WaypointData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "mapId")
        m_mapId = readUInt(field->getValue());
    
    else if(field->getName() == "subAreaId")
        m_subAreaId = readUInt(field->getValue());
    
  }
}

