#include "DungeonData.h"

int DungeonData::getId() const
{
  return m_id;
}

uint DungeonData::getNameId() const
{
  return m_nameId;
}

int DungeonData::getOptimalPlayerLevel() const
{
  return m_optimalPlayerLevel;
}

QList<int> DungeonData::getMapIds() const
{
  return m_mapIds;
}

int DungeonData::getEntranceMapId() const
{
  return m_entranceMapId;
}

int DungeonData::getExitMapId() const
{
  return m_exitMapId;
}

QString DungeonData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void DungeonData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "optimalPlayerLevel")
        m_optimalPlayerLevel = readInt(field->getValue());
    
    else if(field->getName() == "mapIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_mapIds << readInt(data);
    }
    
    else if(field->getName() == "entranceMapId")
        m_entranceMapId = readInt(field->getValue());
    
    else if(field->getName() == "exitMapId")
        m_exitMapId = readInt(field->getValue());
    
  }
}

