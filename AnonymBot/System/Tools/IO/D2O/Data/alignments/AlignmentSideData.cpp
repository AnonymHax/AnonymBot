#include "AlignmentSideData.h"

int AlignmentSideData::getId() const
{
  return m_id;
}

uint AlignmentSideData::getNameId() const
{
  return m_nameId;
}

bool AlignmentSideData::getCanConquest() const
{
  return m_canConquest;
}

QString AlignmentSideData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void AlignmentSideData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "canConquest")
        m_canConquest = readBool(field->getValue());
    
  }
}

