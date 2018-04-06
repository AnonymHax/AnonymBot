#include "EffectInstanceDurationData.h"

uint EffectInstanceDurationData::getDays() const
{
  return m_days;
}

uint EffectInstanceDurationData::getHours() const
{
  return m_hours;
}

uint EffectInstanceDurationData::getMinutes() const
{
  return m_minutes;
}

void EffectInstanceDurationData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  EffectInstanceData::loadData(fields, I18n);
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "days")
        m_days = readUInt(field->getValue());
    
    else if(field->getName() == "hours")
        m_hours = readUInt(field->getValue());
    
    else if(field->getName() == "minutes")
        m_minutes = readUInt(field->getValue());
    
  }
}

