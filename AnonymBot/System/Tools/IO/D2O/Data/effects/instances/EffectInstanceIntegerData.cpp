#include "EffectInstanceIntegerData.h"

int EffectInstanceIntegerData::getValue() const
{
  return m_value;
}

void EffectInstanceIntegerData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  EffectInstanceData::loadData(fields, I18n);
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "value")
        m_value = readInt(field->getValue());
    
  }
}

