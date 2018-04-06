#include "MountBehaviorData.h"

uint MountBehaviorData::getId() const
{
  return m_id;
}

uint MountBehaviorData::getNameId() const
{
  return m_nameId;
}

uint MountBehaviorData::getDescriptionId() const
{
  return m_descriptionId;
}

QString MountBehaviorData::getName() const
{
  return m_I18n->getText(m_nameId);
}

QString MountBehaviorData::getDescription() const
{
  return m_I18n->getText(m_descriptionId);
}

void MountBehaviorData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "descriptionId")
        m_descriptionId = readUInt(field->getValue());
    
  }
}

