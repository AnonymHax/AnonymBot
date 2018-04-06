#include "AlignmentOrderData.h"

int AlignmentOrderData::getId() const
{
  return m_id;
}

uint AlignmentOrderData::getNameId() const
{
  return m_nameId;
}

uint AlignmentOrderData::getSideId() const
{
  return m_sideId;
}

QString AlignmentOrderData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void AlignmentOrderData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "sideId")
        m_sideId = readUInt(field->getValue());
    
  }
}

