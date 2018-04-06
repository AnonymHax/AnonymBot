#include "EffectInstanceMinMaxData.h"

uint EffectInstanceMinMaxData::getMin() const
{
  return m_min;
}

uint EffectInstanceMinMaxData::getMax() const
{
  return m_max;
}

void EffectInstanceMinMaxData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  EffectInstanceData::loadData(fields, I18n);
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "min")
        m_min = readUInt(field->getValue());
    
    else if(field->getName() == "max")
        m_max = readUInt(field->getValue());
    
  }
}

