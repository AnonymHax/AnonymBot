#include "QuestStepRewardsData.h"

uint QuestStepRewardsData::getId() const
{
  return m_id;
}

uint QuestStepRewardsData::getStepId() const
{
  return m_stepId;
}

int QuestStepRewardsData::getLevelMin() const
{
  return m_levelMin;
}

int QuestStepRewardsData::getLevelMax() const
{
  return m_levelMax;
}

QList<QList<uint>> QuestStepRewardsData::getItemsReward() const
{
  return m_itemsReward;
}

QList<uint> QuestStepRewardsData::getEmotesReward() const
{
  return m_emotesReward;
}

QList<uint> QuestStepRewardsData::getJobsReward() const
{
  return m_jobsReward;
}

QList<uint> QuestStepRewardsData::getSpellsReward() const
{
  return m_spellsReward;
}

void QuestStepRewardsData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "stepId")
        m_stepId = readUInt(field->getValue());
    
    else if(field->getName() == "levelMin")
        m_levelMin = readInt(field->getValue());
    
    else if(field->getName() == "levelMax")
        m_levelMax = readInt(field->getValue());
    
    else if(field->getName() == "itemsReward")
    {
      foreach(const QByteArray &firstList, readVector(field->getValue()))
      {
        QList<uint> secondList;
        
        foreach (const QByteArray &data, readVector(firstList))
            secondList << readUInt(data);
        
        m_itemsReward << secondList;
      }
    }
    
    else if(field->getName() == "emotesReward")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_emotesReward << readUInt(data);
    }
    
    else if(field->getName() == "jobsReward")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_jobsReward << readUInt(data);
    }
    
    else if(field->getName() == "spellsReward")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_spellsReward << readUInt(data);
    }
    
  }
}

