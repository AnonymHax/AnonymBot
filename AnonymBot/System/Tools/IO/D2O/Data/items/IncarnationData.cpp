#include "IncarnationData.h"

uint IncarnationData::getId() const
{
  return m_id;
}

QString IncarnationData::getLookMale() const
{
  return m_lookMale;
}

QString IncarnationData::getLookFemale() const
{
  return m_lookFemale;
}

void IncarnationData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "lookMale")
        m_lookMale = readUTF(field->getValue());
    
    else if(field->getName() == "lookFemale")
        m_lookFemale = readUTF(field->getValue());
    
  }
}

