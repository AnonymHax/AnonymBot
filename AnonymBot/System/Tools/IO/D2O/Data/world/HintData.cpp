#include "HintData.h"

int HintData::getId() const
{
  return m_id;
}

uint HintData::getGfx() const
{
  return m_gfx;
}

uint HintData::getNameId() const
{
  return m_nameId;
}

uint HintData::getMapId() const
{
  return m_mapId;
}

uint HintData::getRealMapId() const
{
  return m_realMapId;
}

int HintData::getX() const
{
  return m_x;
}

int HintData::getY() const
{
  return m_y;
}

bool HintData::getOutdoor() const
{
  return m_outdoor;
}

int HintData::getSubareaId() const
{
  return m_subareaId;
}

int HintData::getWorldMapId() const
{
  return m_worldMapId;
}

uint HintData::getLevel() const
{
  return m_level;
}

QString HintData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void HintData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "gfx")
        m_gfx = readUInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "mapId")
        m_mapId = readUInt(field->getValue());
    
    else if(field->getName() == "realMapId")
        m_realMapId = readUInt(field->getValue());
    
    else if(field->getName() == "x")
        m_x = readInt(field->getValue());
    
    else if(field->getName() == "y")
        m_y = readInt(field->getValue());
    
    else if(field->getName() == "outdoor")
        m_outdoor = readBool(field->getValue());
    
    else if(field->getName() == "subareaId")
        m_subareaId = readInt(field->getValue());
    
    else if(field->getName() == "worldMapId")
        m_worldMapId = readInt(field->getValue());
    
    else if(field->getName() == "level")
        m_level = readUInt(field->getValue());
    
  }
}

