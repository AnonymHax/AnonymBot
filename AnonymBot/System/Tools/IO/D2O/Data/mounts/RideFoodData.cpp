#include "RideFoodData.h"

QString RideFoodData::getMODULE() const
{
  return m_MODULE;
}

uint RideFoodData::getGid() const
{
  return m_gid;
}

uint RideFoodData::getTypeId() const
{
  return m_typeId;
}

void RideFoodData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "MODULE")
        m_MODULE = readUTF(field->getValue());
    
    else if(field->getName() == "gid")
        m_gid = readUInt(field->getValue());
    
    else if(field->getName() == "typeId")
        m_typeId = readUInt(field->getValue());
    
  }
}

