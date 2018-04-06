#include "AchievementRewardData.h"

uint AchievementRewardData::getId() const
{
  return m_id;
}

uint AchievementRewardData::getAchievementId() const
{
  return m_achievementId;
}

int AchievementRewardData::getLevelMin() const
{
  return m_levelMin;
}

int AchievementRewardData::getLevelMax() const
{
  return m_levelMax;
}

QList<uint> AchievementRewardData::getItemsReward() const
{
  return m_itemsReward;
}

QList<uint> AchievementRewardData::getItemsQuantityReward() const
{
  return m_itemsQuantityReward;
}

QList<uint> AchievementRewardData::getEmotesReward() const
{
  return m_emotesReward;
}

QList<uint> AchievementRewardData::getSpellsReward() const
{
  return m_spellsReward;
}

QList<uint> AchievementRewardData::getTitlesReward() const
{
  return m_titlesReward;
}

QList<uint> AchievementRewardData::getOrnamentsReward() const
{
  return m_ornamentsReward;
}

void AchievementRewardData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "achievementId")
        m_achievementId = readUInt(field->getValue());
    
    else if(field->getName() == "levelMin")
        m_levelMin = readInt(field->getValue());
    
    else if(field->getName() == "levelMax")
        m_levelMax = readInt(field->getValue());
    
    else if(field->getName() == "itemsReward")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_itemsReward << readUInt(data);
    }
    
    else if(field->getName() == "itemsQuantityReward")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_itemsQuantityReward << readUInt(data);
    }
    
    else if(field->getName() == "emotesReward")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_emotesReward << readUInt(data);
    }
    
    else if(field->getName() == "spellsReward")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_spellsReward << readUInt(data);
    }
    
    else if(field->getName() == "titlesReward")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_titlesReward << readUInt(data);
    }
    
    else if(field->getName() == "ornamentsReward")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_ornamentsReward << readUInt(data);
    }
    
  }
}

