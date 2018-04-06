#include "IdolData.h"

int IdolData::getId() const
{
  return m_id;
}

QString IdolData::getDescription() const
{
  return m_description;
}

int IdolData::getCategoryId() const
{
  return m_categoryId;
}

int IdolData::getItemId() const
{
  return m_itemId;
}

bool IdolData::getGroupOnly() const
{
  return m_groupOnly;
}

int IdolData::getSpellPairId() const
{
  return m_spellPairId;
}

int IdolData::getScore() const
{
  return m_score;
}

int IdolData::getExperienceBonus() const
{
  return m_experienceBonus;
}

int IdolData::getDropBonus() const
{
  return m_dropBonus;
}

QList<int> IdolData::getSynergyIdolsIds() const
{
  return m_synergyIdolsIds;
}

QList<double> IdolData::getSynergyIdolsCoeff() const
{
  return m_synergyIdolsCoeff;
}

QList<int> IdolData::getIncompatibleMonsters() const
{
  return m_incompatibleMonsters;
}

void IdolData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "description")
        m_description = readUTF(field->getValue());
    
    else if(field->getName() == "categoryId")
        m_categoryId = readInt(field->getValue());
    
    else if(field->getName() == "itemId")
        m_itemId = readInt(field->getValue());
    
    else if(field->getName() == "groupOnly")
        m_groupOnly = readBool(field->getValue());
    
    else if(field->getName() == "spellPairId")
        m_spellPairId = readInt(field->getValue());
    
    else if(field->getName() == "score")
        m_score = readInt(field->getValue());
    
    else if(field->getName() == "experienceBonus")
        m_experienceBonus = readInt(field->getValue());
    
    else if(field->getName() == "dropBonus")
        m_dropBonus = readInt(field->getValue());
    
    else if(field->getName() == "synergyIdolsIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_synergyIdolsIds << readInt(data);
    }
    
    else if(field->getName() == "synergyIdolsCoeff")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_synergyIdolsCoeff << readDouble(data);
    }
    
    else if(field->getName() == "incompatibleMonsters")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_incompatibleMonsters << readInt(data);
    }
    
  }
}

