#include "SkinMappingData.h"

int SkinMappingData::getId() const
{
  return m_id;
}

int SkinMappingData::getLowDefId() const
{
  return m_lowDefId;
}

void SkinMappingData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "lowDefId")
        m_lowDefId = readInt(field->getValue());
    
  }
}

