#include "MapReferenceData.h"

int MapReferenceData::getId() const
{
  return m_id;
}

uint MapReferenceData::getMapId() const
{
  return m_mapId;
}

int MapReferenceData::getCellId() const
{
  return m_cellId;
}

void MapReferenceData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "mapId")
        m_mapId = readUInt(field->getValue());
    
    else if(field->getName() == "cellId")
        m_cellId = readInt(field->getValue());
    
  }
}

