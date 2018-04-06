#include "TaxCollectorFirstnameData.h"

int TaxCollectorFirstnameData::getId() const
{
  return m_id;
}

uint TaxCollectorFirstnameData::getFirstnameId() const
{
  return m_firstnameId;
}

QString TaxCollectorFirstnameData::getFirstname() const
{
  return m_I18n->getText(m_firstnameId);
}

void TaxCollectorFirstnameData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "firstnameId")
        m_firstnameId = readUInt(field->getValue());
    
  }
}

