#include "MountFamilyData.h"

uint MountFamilyData::getId() const
{
  return m_id;
}

uint MountFamilyData::getNameId() const
{
  return m_nameId;
}

QString MountFamilyData::getHeadUri() const
{
  return m_headUri;
}

QString MountFamilyData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void MountFamilyData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "headUri")
        m_headUri = readUTF(field->getValue());
    
  }
}

