#include "LivingObjectSkinJntMoodData.h"

int LivingObjectSkinJntMoodData::getSkinId() const
{
  return m_skinId;
}

QList<QList<int>> LivingObjectSkinJntMoodData::getMoods() const
{
  return m_moods;
}

void LivingObjectSkinJntMoodData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "skinId")
        m_skinId = readInt(field->getValue());
    
    else if(field->getName() == "moods")
    {
      foreach(const QByteArray &firstList, readVector(field->getValue()))
      {
        QList<int> secondList;
        
        foreach (const QByteArray &data, readVector(firstList))
            secondList << readInt(data);
        
        m_moods << secondList;
      }
    }
    
  }
}

