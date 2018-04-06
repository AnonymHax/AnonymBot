#include "RankNameData.h"

int RankNameData::getId() const
{
  return m_id;
}

uint RankNameData::getNameId() const
{
  return m_nameId;
}

int RankNameData::getOrder() const
{
  return m_order;
}

QString RankNameData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void RankNameData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "order")
        m_order = readInt(field->getValue());
    
  }
}

