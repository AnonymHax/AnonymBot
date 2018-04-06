#include "SuperAreaData.h"

int SuperAreaData::getId() const
{
  return m_id;
}

uint SuperAreaData::getNameId() const
{
  return m_nameId;
}

uint SuperAreaData::getWorldmapId() const
{
  return m_worldmapId;
}

bool SuperAreaData::getHasWorldMap() const
{
  return m_hasWorldMap;
}

QString SuperAreaData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void SuperAreaData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "worldmapId")
        m_worldmapId = readUInt(field->getValue());
    
    else if(field->getName() == "hasWorldMap")
        m_hasWorldMap = readBool(field->getValue());
    
  }
}

