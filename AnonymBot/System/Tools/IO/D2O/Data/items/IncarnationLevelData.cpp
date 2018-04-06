#include "IncarnationLevelData.h"

int IncarnationLevelData::getId() const
{
  return m_id;
}

int IncarnationLevelData::getIncarnationId() const
{
  return m_incarnationId;
}

int IncarnationLevelData::getLevel() const
{
  return m_level;
}

uint IncarnationLevelData::getRequiredXp() const
{
  return m_requiredXp;
}

void IncarnationLevelData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "incarnationId")
        m_incarnationId = readInt(field->getValue());
    
    else if(field->getName() == "level")
        m_level = readInt(field->getValue());
    
    else if(field->getName() == "requiredXp")
        m_requiredXp = readUInt(field->getValue());
    
  }
}

