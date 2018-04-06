#include "MonsterGradeData.h"

uint MonsterGradeData::getGrade() const
{
  return m_grade;
}

int MonsterGradeData::getMonsterId() const
{
  return m_monsterId;
}

uint MonsterGradeData::getLevel() const
{
  return m_level;
}

int MonsterGradeData::getVitality() const
{
  return m_vitality;
}

int MonsterGradeData::getPaDodge() const
{
  return m_paDodge;
}

int MonsterGradeData::getPmDodge() const
{
  return m_pmDodge;
}

int MonsterGradeData::getWisdom() const
{
  return m_wisdom;
}

int MonsterGradeData::getEarthResistance() const
{
  return m_earthResistance;
}

int MonsterGradeData::getAirResistance() const
{
  return m_airResistance;
}

int MonsterGradeData::getFireResistance() const
{
  return m_fireResistance;
}

int MonsterGradeData::getWaterResistance() const
{
  return m_waterResistance;
}

int MonsterGradeData::getNeutralResistance() const
{
  return m_neutralResistance;
}

int MonsterGradeData::getGradeXp() const
{
  return m_gradeXp;
}

int MonsterGradeData::getLifePoints() const
{
  return m_lifePoints;
}

int MonsterGradeData::getActionPoints() const
{
  return m_actionPoints;
}

int MonsterGradeData::getMovementPoints() const
{
  return m_movementPoints;
}

int MonsterGradeData::getDamageReflect() const
{
  return m_damageReflect;
}

uint MonsterGradeData::getHiddenLevel() const
{
  return m_hiddenLevel;
}

void MonsterGradeData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "grade")
        m_grade = readUInt(field->getValue());
    
    else if(field->getName() == "monsterId")
        m_monsterId = readInt(field->getValue());
    
    else if(field->getName() == "level")
        m_level = readUInt(field->getValue());
    
    else if(field->getName() == "vitality")
        m_vitality = readInt(field->getValue());
    
    else if(field->getName() == "paDodge")
        m_paDodge = readInt(field->getValue());
    
    else if(field->getName() == "pmDodge")
        m_pmDodge = readInt(field->getValue());
    
    else if(field->getName() == "wisdom")
        m_wisdom = readInt(field->getValue());
    
    else if(field->getName() == "earthResistance")
        m_earthResistance = readInt(field->getValue());
    
    else if(field->getName() == "airResistance")
        m_airResistance = readInt(field->getValue());
    
    else if(field->getName() == "fireResistance")
        m_fireResistance = readInt(field->getValue());
    
    else if(field->getName() == "waterResistance")
        m_waterResistance = readInt(field->getValue());
    
    else if(field->getName() == "neutralResistance")
        m_neutralResistance = readInt(field->getValue());
    
    else if(field->getName() == "gradeXp")
        m_gradeXp = readInt(field->getValue());
    
    else if(field->getName() == "lifePoints")
        m_lifePoints = readInt(field->getValue());
    
    else if(field->getName() == "actionPoints")
        m_actionPoints = readInt(field->getValue());
    
    else if(field->getName() == "movementPoints")
        m_movementPoints = readInt(field->getValue());
    
    else if(field->getName() == "damageReflect")
        m_damageReflect = readInt(field->getValue());
    
    else if(field->getName() == "hiddenLevel")
        m_hiddenLevel = readUInt(field->getValue());
    
  }
}

