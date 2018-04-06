#include "EffectInstanceDateData.h"

uint EffectInstanceDateData::getYear() const
{
  return m_year;
}

uint EffectInstanceDateData::getMonth() const
{
  return m_month;
}

uint EffectInstanceDateData::getDay() const
{
  return m_day;
}

uint EffectInstanceDateData::getHour() const
{
  return m_hour;
}

uint EffectInstanceDateData::getMinute() const
{
  return m_minute;
}

void EffectInstanceDateData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  EffectInstanceData::loadData(fields, I18n);
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "year")
        m_year = readUInt(field->getValue());
    
    else if(field->getName() == "month")
        m_month = readUInt(field->getValue());
    
    else if(field->getName() == "day")
        m_day = readUInt(field->getValue());
    
    else if(field->getName() == "hour")
        m_hour = readUInt(field->getValue());
    
    else if(field->getName() == "minute")
        m_minute = readUInt(field->getValue());
    
  }
}

