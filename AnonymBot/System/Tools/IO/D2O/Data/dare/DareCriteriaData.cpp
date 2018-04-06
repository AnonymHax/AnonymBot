#include "DareCriteriaData.h"

uint DareCriteriaData::getId() const
{
  return m_id;
}

uint DareCriteriaData::getNameId() const
{
  return m_nameId;
}

uint DareCriteriaData::getMaxOccurence() const
{
  return m_maxOccurence;
}

uint DareCriteriaData::getMaxParameters() const
{
  return m_maxParameters;
}

int DareCriteriaData::getMinParameterBound() const
{
  return m_minParameterBound;
}

int DareCriteriaData::getMaxParameterBound() const
{
  return m_maxParameterBound;
}

QString DareCriteriaData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void DareCriteriaData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "maxOccurence")
        m_maxOccurence = readUInt(field->getValue());
    
    else if(field->getName() == "maxParameters")
        m_maxParameters = readUInt(field->getValue());
    
    else if(field->getName() == "minParameterBound")
        m_minParameterBound = readInt(field->getValue());
    
    else if(field->getName() == "maxParameterBound")
        m_maxParameterBound = readInt(field->getValue());
    
  }
}

