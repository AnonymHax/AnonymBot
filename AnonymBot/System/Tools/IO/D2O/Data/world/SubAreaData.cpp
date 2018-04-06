#include "SubAreaData.h"

int SubAreaData::getId() const
{
  return m_id;
}

uint SubAreaData::getNameId() const
{
  return m_nameId;
}

int SubAreaData::getAreaId() const
{
  return m_areaId;
}

QList<AmbientSoundData> SubAreaData::getAmbientSounds() const
{
  return m_ambientSounds;
}

QList<QList<int>> SubAreaData::getPlaylists() const
{
  return m_playlists;
}

QList<uint> SubAreaData::getMapIds() const
{
  return m_mapIds;
}

QList<int> SubAreaData::getShape() const
{
  return m_shape;
}

QList<uint> SubAreaData::getCustomWorldMap() const
{
  return m_customWorldMap;
}

int SubAreaData::getPackId() const
{
  return m_packId;
}

uint SubAreaData::getLevel() const
{
  return m_level;
}

bool SubAreaData::getIsConquestVillage() const
{
  return m_isConquestVillage;
}

bool SubAreaData::getBasicAccountAllowed() const
{
  return m_basicAccountAllowed;
}

bool SubAreaData::getDisplayOnWorldMap() const
{
  return m_displayOnWorldMap;
}

QList<uint> SubAreaData::getMonsters() const
{
  return m_monsters;
}

QList<uint> SubAreaData::getEntranceMapIds() const
{
  return m_entranceMapIds;
}

QList<uint> SubAreaData::getExitMapIds() const
{
  return m_exitMapIds;
}

bool SubAreaData::getCapturable() const
{
  return m_capturable;
}

QList<uint> SubAreaData::getAchievements() const
{
  return m_achievements;
}

QList<QList<int>> SubAreaData::getQuests() const
{
  return m_quests;
}

QList<QList<int>> SubAreaData::getNpcs() const
{
  return m_npcs;
}

int SubAreaData::getExploreAchievementId() const
{
  return m_exploreAchievementId;
}

bool SubAreaData::getIsDiscovered() const
{
  return m_isDiscovered;
}

QList<int> SubAreaData::getHarvestables() const
{
  return m_harvestables;
}

QString SubAreaData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void SubAreaData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "areaId")
        m_areaId = readInt(field->getValue());
    
    else if(field->getName() == "ambientSounds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_ambientSounds << *qSharedPointerCast<AmbientSoundData>(readObject(data, field)).data();
    }
    
    else if(field->getName() == "playlists")
    {
      foreach(const QByteArray &firstList, readVector(field->getValue()))
      {
        QList<int> secondList;
        
        foreach (const QByteArray &data, readVector(firstList))
            secondList << readInt(data);
        
        m_playlists << secondList;
      }
    }
    
    else if(field->getName() == "mapIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_mapIds << readUInt(data);
    }
    
    else if(field->getName() == "shape")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_shape << readInt(data);
    }
    
    else if(field->getName() == "customWorldMap")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_customWorldMap << readUInt(data);
    }
    
    else if(field->getName() == "packId")
        m_packId = readInt(field->getValue());
    
    else if(field->getName() == "level")
        m_level = readUInt(field->getValue());
    
    else if(field->getName() == "isConquestVillage")
        m_isConquestVillage = readBool(field->getValue());
    
    else if(field->getName() == "basicAccountAllowed")
        m_basicAccountAllowed = readBool(field->getValue());
    
    else if(field->getName() == "displayOnWorldMap")
        m_displayOnWorldMap = readBool(field->getValue());
    
    else if(field->getName() == "monsters")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_monsters << readUInt(data);
    }
    
    else if(field->getName() == "entranceMapIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_entranceMapIds << readUInt(data);
    }
    
    else if(field->getName() == "exitMapIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_exitMapIds << readUInt(data);
    }
    
    else if(field->getName() == "capturable")
        m_capturable = readBool(field->getValue());
    
    else if(field->getName() == "achievements")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_achievements << readUInt(data);
    }
    
    else if(field->getName() == "quests")
    {
      foreach(const QByteArray &firstList, readVector(field->getValue()))
      {
        QList<int> secondList;
        
        foreach (const QByteArray &data, readVector(firstList))
            secondList << readInt(data);
        
        m_quests << secondList;
      }
    }
    
    else if(field->getName() == "npcs")
    {
      foreach(const QByteArray &firstList, readVector(field->getValue()))
      {
        QList<int> secondList;
        
        foreach (const QByteArray &data, readVector(firstList))
            secondList << readInt(data);
        
        m_npcs << secondList;
      }
    }
    
    else if(field->getName() == "exploreAchievementId")
        m_exploreAchievementId = readInt(field->getValue());
    
    else if(field->getName() == "isDiscovered")
        m_isDiscovered = readBool(field->getValue());
    
    else if(field->getName() == "harvestables")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_harvestables << readInt(data);
    }
    
  }
}

