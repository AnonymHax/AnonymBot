#include "WorldMapData.h"

int WorldMapData::getId() const
{
  return m_id;
}

uint WorldMapData::getNameId() const
{
  return m_nameId;
}

int WorldMapData::getOrigineX() const
{
  return m_origineX;
}

int WorldMapData::getOrigineY() const
{
  return m_origineY;
}

double WorldMapData::getMapWidth() const
{
  return m_mapWidth;
}

double WorldMapData::getMapHeight() const
{
  return m_mapHeight;
}

uint WorldMapData::getHorizontalChunck() const
{
  return m_horizontalChunck;
}

uint WorldMapData::getVerticalChunck() const
{
  return m_verticalChunck;
}

bool WorldMapData::getViewableEverywhere() const
{
  return m_viewableEverywhere;
}

double WorldMapData::getMinScale() const
{
  return m_minScale;
}

double WorldMapData::getMaxScale() const
{
  return m_maxScale;
}

double WorldMapData::getStartScale() const
{
  return m_startScale;
}

int WorldMapData::getCenterX() const
{
  return m_centerX;
}

int WorldMapData::getCenterY() const
{
  return m_centerY;
}

int WorldMapData::getTotalWidth() const
{
  return m_totalWidth;
}

int WorldMapData::getTotalHeight() const
{
  return m_totalHeight;
}

QList<QString> WorldMapData::getZoom() const
{
  return m_zoom;
}

QString WorldMapData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void WorldMapData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "origineX")
        m_origineX = readInt(field->getValue());
    
    else if(field->getName() == "origineY")
        m_origineY = readInt(field->getValue());
    
    else if(field->getName() == "mapWidth")
        m_mapWidth = readDouble(field->getValue());
    
    else if(field->getName() == "mapHeight")
        m_mapHeight = readDouble(field->getValue());
    
    else if(field->getName() == "horizontalChunck")
        m_horizontalChunck = readUInt(field->getValue());
    
    else if(field->getName() == "verticalChunck")
        m_verticalChunck = readUInt(field->getValue());
    
    else if(field->getName() == "viewableEverywhere")
        m_viewableEverywhere = readBool(field->getValue());
    
    else if(field->getName() == "minScale")
        m_minScale = readDouble(field->getValue());
    
    else if(field->getName() == "maxScale")
        m_maxScale = readDouble(field->getValue());
    
    else if(field->getName() == "startScale")
        m_startScale = readDouble(field->getValue());
    
    else if(field->getName() == "centerX")
        m_centerX = readInt(field->getValue());
    
    else if(field->getName() == "centerY")
        m_centerY = readInt(field->getValue());
    
    else if(field->getName() == "totalWidth")
        m_totalWidth = readInt(field->getValue());
    
    else if(field->getName() == "totalHeight")
        m_totalHeight = readInt(field->getValue());
    
    else if(field->getName() == "zoom")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_zoom << readUTF(data);
    }
    
  }
}

