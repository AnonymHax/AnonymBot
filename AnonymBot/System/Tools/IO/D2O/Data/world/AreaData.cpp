#include "AreaData.h"

int AreaData::getId() const
{
  return m_id;
}

uint AreaData::getNameId() const
{
  return m_nameId;
}

int AreaData::getSuperAreaId() const
{
  return m_superAreaId;
}

bool AreaData::getContainHouses() const
{
  return m_containHouses;
}

bool AreaData::getContainPaddocks() const
{
  return m_containPaddocks;
}

uint AreaData::getWorldmapId() const
{
  return m_worldmapId;
}

bool AreaData::getHasWorldMap() const
{
  return m_hasWorldMap;
}

QString AreaData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void AreaData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "superAreaId")
        m_superAreaId = readInt(field->getValue());
    
    else if(field->getName() == "containHouses")
        m_containHouses = readBool(field->getValue());
    
    else if(field->getName() == "containPaddocks")
        m_containPaddocks = readBool(field->getValue());
    
    else if(field->getName() == "worldmapId")
        m_worldmapId = readUInt(field->getValue());
    
    else if(field->getName() == "hasWorldMap")
        m_hasWorldMap = readBool(field->getValue());
    
  }
}

