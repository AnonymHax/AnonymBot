#include "InteractiveData.h"

int InteractiveData::getId() const
{
  return m_id;
}

uint InteractiveData::getNameId() const
{
  return m_nameId;
}

int InteractiveData::getActionId() const
{
  return m_actionId;
}

bool InteractiveData::getDisplayTooltip() const
{
  return m_displayTooltip;
}

QString InteractiveData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void InteractiveData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "actionId")
        m_actionId = readInt(field->getValue());
    
    else if(field->getName() == "displayTooltip")
        m_displayTooltip = readBool(field->getValue());
    
  }
}

