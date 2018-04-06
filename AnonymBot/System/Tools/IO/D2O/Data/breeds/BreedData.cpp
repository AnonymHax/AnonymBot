#include "BreedData.h"

int BreedData::getId() const
{
  return m_id;
}

uint BreedData::getShortNameId() const
{
  return m_shortNameId;
}

uint BreedData::getLongNameId() const
{
  return m_longNameId;
}

uint BreedData::getDescriptionId() const
{
  return m_descriptionId;
}

uint BreedData::getGameplayDescriptionId() const
{
  return m_gameplayDescriptionId;
}

QString BreedData::getMaleLook() const
{
  return m_maleLook;
}

QString BreedData::getFemaleLook() const
{
  return m_femaleLook;
}

uint BreedData::getCreatureBonesId() const
{
  return m_creatureBonesId;
}

int BreedData::getMaleArtwork() const
{
  return m_maleArtwork;
}

int BreedData::getFemaleArtwork() const
{
  return m_femaleArtwork;
}

QList<QList<uint>> BreedData::getStatsPointsForStrength() const
{
  return m_statsPointsForStrength;
}

QList<QList<uint>> BreedData::getStatsPointsForIntelligence() const
{
  return m_statsPointsForIntelligence;
}

QList<QList<uint>> BreedData::getStatsPointsForChance() const
{
  return m_statsPointsForChance;
}

QList<QList<uint>> BreedData::getStatsPointsForAgility() const
{
  return m_statsPointsForAgility;
}

QList<QList<uint>> BreedData::getStatsPointsForVitality() const
{
  return m_statsPointsForVitality;
}

QList<QList<uint>> BreedData::getStatsPointsForWisdom() const
{
  return m_statsPointsForWisdom;
}

QList<uint> BreedData::getBreedSpellsId() const
{
  return m_breedSpellsId;
}

QList<BreedRoleByBreedData> BreedData::getBreedRoles() const
{
  return m_breedRoles;
}

QList<uint> BreedData::getMaleColors() const
{
  return m_maleColors;
}

QList<uint> BreedData::getFemaleColors() const
{
  return m_femaleColors;
}

uint BreedData::getSpawnMap() const
{
  return m_spawnMap;
}

uint BreedData::getComplexity() const
{
  return m_complexity;
}

uint BreedData::getSortIndex() const
{
  return m_sortIndex;
}

QString BreedData::getShortName() const
{
  return m_I18n->getText(m_shortNameId);
}

QString BreedData::getLongName() const
{
  return m_I18n->getText(m_longNameId);
}

QString BreedData::getDescription() const
{
  return m_I18n->getText(m_descriptionId);
}

QString BreedData::getGameplayDescription() const
{
  return m_I18n->getText(m_gameplayDescriptionId);
}

void BreedData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "shortNameId")
        m_shortNameId = readUInt(field->getValue());
    
    else if(field->getName() == "longNameId")
        m_longNameId = readUInt(field->getValue());
    
    else if(field->getName() == "descriptionId")
        m_descriptionId = readUInt(field->getValue());
    
    else if(field->getName() == "gameplayDescriptionId")
        m_gameplayDescriptionId = readUInt(field->getValue());
    
    else if(field->getName() == "maleLook")
        m_maleLook = readUTF(field->getValue());
    
    else if(field->getName() == "femaleLook")
        m_femaleLook = readUTF(field->getValue());
    
    else if(field->getName() == "creatureBonesId")
        m_creatureBonesId = readUInt(field->getValue());
    
    else if(field->getName() == "maleArtwork")
        m_maleArtwork = readInt(field->getValue());
    
    else if(field->getName() == "femaleArtwork")
        m_femaleArtwork = readInt(field->getValue());
    
    else if(field->getName() == "statsPointsForStrength")
    {
      foreach(const QByteArray &firstList, readVector(field->getValue()))
      {
        QList<uint> secondList;
        
        foreach (const QByteArray &data, readVector(firstList))
            secondList << readUInt(data);
        
        m_statsPointsForStrength << secondList;
      }
    }
    
    else if(field->getName() == "statsPointsForIntelligence")
    {
      foreach(const QByteArray &firstList, readVector(field->getValue()))
      {
        QList<uint> secondList;
        
        foreach (const QByteArray &data, readVector(firstList))
            secondList << readUInt(data);
        
        m_statsPointsForIntelligence << secondList;
      }
    }
    
    else if(field->getName() == "statsPointsForChance")
    {
      foreach(const QByteArray &firstList, readVector(field->getValue()))
      {
        QList<uint> secondList;
        
        foreach (const QByteArray &data, readVector(firstList))
            secondList << readUInt(data);
        
        m_statsPointsForChance << secondList;
      }
    }
    
    else if(field->getName() == "statsPointsForAgility")
    {
      foreach(const QByteArray &firstList, readVector(field->getValue()))
      {
        QList<uint> secondList;
        
        foreach (const QByteArray &data, readVector(firstList))
            secondList << readUInt(data);
        
        m_statsPointsForAgility << secondList;
      }
    }
    
    else if(field->getName() == "statsPointsForVitality")
    {
      foreach(const QByteArray &firstList, readVector(field->getValue()))
      {
        QList<uint> secondList;
        
        foreach (const QByteArray &data, readVector(firstList))
            secondList << readUInt(data);
        
        m_statsPointsForVitality << secondList;
      }
    }
    
    else if(field->getName() == "statsPointsForWisdom")
    {
      foreach(const QByteArray &firstList, readVector(field->getValue()))
      {
        QList<uint> secondList;
        
        foreach (const QByteArray &data, readVector(firstList))
            secondList << readUInt(data);
        
        m_statsPointsForWisdom << secondList;
      }
    }
    
    else if(field->getName() == "breedSpellsId")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_breedSpellsId << readUInt(data);
    }
    
    else if(field->getName() == "breedRoles")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_breedRoles << *qSharedPointerCast<BreedRoleByBreedData>(readObject(data, field)).data();
    }
    
    else if(field->getName() == "maleColors")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_maleColors << readUInt(data);
    }
    
    else if(field->getName() == "femaleColors")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_femaleColors << readUInt(data);
    }
    
    else if(field->getName() == "spawnMap")
        m_spawnMap = readUInt(field->getValue());
    
    else if(field->getName() == "complexity")
        m_complexity = readUInt(field->getValue());
    
    else if(field->getName() == "sortIndex")
        m_sortIndex = readUInt(field->getValue());
    
  }
}

