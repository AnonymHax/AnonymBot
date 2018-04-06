#include "AmbientSoundData.h"

int AmbientSoundData::getCriterionId() const
{
  return m_criterionId;
}

uint AmbientSoundData::getSilenceMin() const
{
  return m_silenceMin;
}

uint AmbientSoundData::getSilenceMax() const
{
  return m_silenceMax;
}

void AmbientSoundData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  PlaylistSoundData::loadData(fields, I18n);
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "criterionId")
        m_criterionId = readInt(field->getValue());
    
    else if(field->getName() == "silenceMin")
        m_silenceMin = readUInt(field->getValue());
    
    else if(field->getName() == "silenceMax")
        m_silenceMax = readUInt(field->getValue());
    
  }
}

