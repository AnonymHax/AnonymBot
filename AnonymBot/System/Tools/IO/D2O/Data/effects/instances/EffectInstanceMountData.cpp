#include "EffectInstanceMountData.h"

double EffectInstanceMountData::getDate() const
{
  return m_date;
}

uint EffectInstanceMountData::getModelId() const
{
  return m_modelId;
}

uint EffectInstanceMountData::getMountId() const
{
  return m_mountId;
}

void EffectInstanceMountData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  EffectInstanceData::loadData(fields, I18n);
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "date")
        m_date = readDouble(field->getValue());
    
    else if(field->getName() == "modelId")
        m_modelId = readUInt(field->getValue());
    
    else if(field->getName() == "mountId")
        m_mountId = readUInt(field->getValue());
    
  }
}

