#include "LegendaryTreasureHuntData.h"

uint LegendaryTreasureHuntData::getId() const
{
  return m_id;
}

uint LegendaryTreasureHuntData::getNameId() const
{
  return m_nameId;
}

uint LegendaryTreasureHuntData::getLevel() const
{
  return m_level;
}

uint LegendaryTreasureHuntData::getChestId() const
{
  return m_chestId;
}

uint LegendaryTreasureHuntData::getMonsterId() const
{
  return m_monsterId;
}

uint LegendaryTreasureHuntData::getMapItemId() const
{
  return m_mapItemId;
}

double LegendaryTreasureHuntData::getXpRatio() const
{
  return m_xpRatio;
}

QString LegendaryTreasureHuntData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void LegendaryTreasureHuntData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "level")
        m_level = readUInt(field->getValue());
    
    else if(field->getName() == "chestId")
        m_chestId = readUInt(field->getValue());
    
    else if(field->getName() == "monsterId")
        m_monsterId = readUInt(field->getValue());
    
    else if(field->getName() == "mapItemId")
        m_mapItemId = readUInt(field->getValue());
    
    else if(field->getName() == "xpRatio")
        m_xpRatio = readDouble(field->getValue());
    
  }
}

