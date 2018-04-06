#include "TaxCollectorNameData.h"

int TaxCollectorNameData::getId() const
{
  return m_id;
}

uint TaxCollectorNameData::getNameId() const
{
  return m_nameId;
}

QString TaxCollectorNameData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void TaxCollectorNameData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
  }
}

