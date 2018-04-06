#include "NpcActionData.h"

int NpcActionData::getId() const
{
  return m_id;
}

int NpcActionData::getRealId() const
{
  return m_realId;
}

uint NpcActionData::getNameId() const
{
  return m_nameId;
}

QString NpcActionData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void NpcActionData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "realId")
        m_realId = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
  }
}

