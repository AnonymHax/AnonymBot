#include "WeaponData.h"

int WeaponData::getApCost() const
{
  return m_apCost;
}

int WeaponData::getMinRange() const
{
  return m_minRange;
}

int WeaponData::getRange() const
{
  return m_range;
}

uint WeaponData::getMaxCastPerTurn() const
{
  return m_maxCastPerTurn;
}

bool WeaponData::getCastInLine() const
{
  return m_castInLine;
}

bool WeaponData::getCastInDiagonal() const
{
  return m_castInDiagonal;
}

bool WeaponData::getCastTestLos() const
{
  return m_castTestLos;
}

int WeaponData::getCriticalHitProbability() const
{
  return m_criticalHitProbability;
}

int WeaponData::getCriticalHitBonus() const
{
  return m_criticalHitBonus;
}

int WeaponData::getCriticalFailureProbability() const
{
  return m_criticalFailureProbability;
}

void WeaponData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  ItemData::loadData(fields, I18n);
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "apCost")
        m_apCost = readInt(field->getValue());
    
    else if(field->getName() == "minRange")
        m_minRange = readInt(field->getValue());
    
    else if(field->getName() == "range")
        m_range = readInt(field->getValue());
    
    else if(field->getName() == "maxCastPerTurn")
        m_maxCastPerTurn = readUInt(field->getValue());
    
    else if(field->getName() == "castInLine")
        m_castInLine = readBool(field->getValue());
    
    else if(field->getName() == "castInDiagonal")
        m_castInDiagonal = readBool(field->getValue());
    
    else if(field->getName() == "castTestLos")
        m_castTestLos = readBool(field->getValue());
    
    else if(field->getName() == "criticalHitProbability")
        m_criticalHitProbability = readInt(field->getValue());
    
    else if(field->getName() == "criticalHitBonus")
        m_criticalHitBonus = readInt(field->getValue());
    
    else if(field->getName() == "criticalFailureProbability")
        m_criticalFailureProbability = readInt(field->getValue());
    
  }
}

