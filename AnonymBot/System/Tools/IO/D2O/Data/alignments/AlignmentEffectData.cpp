#include "AlignmentEffectData.h"

int AlignmentEffectData::getId() const
{
  return m_id;
}

uint AlignmentEffectData::getCharacteristicId() const
{
  return m_characteristicId;
}

uint AlignmentEffectData::getDescriptionId() const
{
  return m_descriptionId;
}

QString AlignmentEffectData::getDescription() const
{
  return m_I18n->getText(m_descriptionId);
}

void AlignmentEffectData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "characteristicId")
        m_characteristicId = readUInt(field->getValue());
    
    else if(field->getName() == "descriptionId")
        m_descriptionId = readUInt(field->getValue());
    
  }
}

