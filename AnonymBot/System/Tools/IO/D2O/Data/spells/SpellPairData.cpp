#include "SpellPairData.h"

int SpellPairData::getId() const
{
  return m_id;
}

uint SpellPairData::getNameId() const
{
  return m_nameId;
}

uint SpellPairData::getDescriptionId() const
{
  return m_descriptionId;
}

uint SpellPairData::getIconId() const
{
  return m_iconId;
}

QString SpellPairData::getName() const
{
  return m_I18n->getText(m_nameId);
}

QString SpellPairData::getDescription() const
{
  return m_I18n->getText(m_descriptionId);
}

void SpellPairData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "descriptionId")
        m_descriptionId = readUInt(field->getValue());
    
    else if(field->getName() == "iconId")
        m_iconId = readUInt(field->getValue());
    
  }
}

