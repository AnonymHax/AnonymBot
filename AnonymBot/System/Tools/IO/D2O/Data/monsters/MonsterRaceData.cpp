#include "MonsterRaceData.h"

int MonsterRaceData::getId() const
{
  return m_id;
}

int MonsterRaceData::getSuperRaceId() const
{
  return m_superRaceId;
}

uint MonsterRaceData::getNameId() const
{
  return m_nameId;
}

QList<uint> MonsterRaceData::getMonsters() const
{
  return m_monsters;
}

QString MonsterRaceData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void MonsterRaceData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "superRaceId")
        m_superRaceId = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "monsters")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_monsters << readUInt(data);
    }
    
  }
}

