#include "SpeakingItemsTriggerData.h"

int SpeakingItemsTriggerData::getTriggersId() const
{
  return m_triggersId;
}

QList<int> SpeakingItemsTriggerData::getTextIds() const
{
  return m_textIds;
}

QList<int> SpeakingItemsTriggerData::getStates() const
{
  return m_states;
}

void SpeakingItemsTriggerData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "triggersId")
        m_triggersId = readInt(field->getValue());
    
    else if(field->getName() == "textIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_textIds << readInt(data);
    }
    
    else if(field->getName() == "states")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_states << readInt(data);
    }
    
  }
}

