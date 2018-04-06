#include "ServerPopulationData.h"

int ServerPopulationData::getId() const
{
  return m_id;
}

uint ServerPopulationData::getNameId() const
{
  return m_nameId;
}

int ServerPopulationData::getWeight() const
{
  return m_weight;
}

QString ServerPopulationData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void ServerPopulationData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "weight")
        m_weight = readInt(field->getValue());
    
  }
}

