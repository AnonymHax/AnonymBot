#include "QuestObjectiveTypeData.h"

uint QuestObjectiveTypeData::getId() const
{
  return m_id;
}

uint QuestObjectiveTypeData::getNameId() const
{
  return m_nameId;
}

QString QuestObjectiveTypeData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void QuestObjectiveTypeData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
  }
}

