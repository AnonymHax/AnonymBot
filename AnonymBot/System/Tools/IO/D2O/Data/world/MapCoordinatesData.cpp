#include "MapCoordinatesData.h"

uint MapCoordinatesData::getCompressedCoords() const
{
  return m_compressedCoords;
}

QList<int> MapCoordinatesData::getMapIds() const
{
  return m_mapIds;
}

void MapCoordinatesData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "compressedCoords")
        m_compressedCoords = readUInt(field->getValue());
    
    else if(field->getName() == "mapIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_mapIds << readInt(data);
    }
    
  }
}

