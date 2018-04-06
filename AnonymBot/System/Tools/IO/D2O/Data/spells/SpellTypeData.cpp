#include "SpellTypeData.h"

int SpellTypeData::getId() const
{
  return m_id;
}

uint SpellTypeData::getLongNameId() const
{
  return m_longNameId;
}

uint SpellTypeData::getShortNameId() const
{
  return m_shortNameId;
}

QString SpellTypeData::getLongName() const
{
  return m_I18n->getText(m_longNameId);
}

QString SpellTypeData::getShortName() const
{
  return m_I18n->getText(m_shortNameId);
}

void SpellTypeData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "longNameId")
        m_longNameId = readUInt(field->getValue());
    
    else if(field->getName() == "shortNameId")
        m_shortNameId = readUInt(field->getValue());
    
  }
}

