#include "FinishMoveData.h"

int FinishMoveData::getId() const
{
  return m_id;
}

int FinishMoveData::getDuration() const
{
  return m_duration;
}

bool FinishMoveData::getFree() const
{
  return m_free;
}

uint FinishMoveData::getNameId() const
{
  return m_nameId;
}

int FinishMoveData::getCategory() const
{
  return m_category;
}

int FinishMoveData::getSpellLevel() const
{
  return m_spellLevel;
}

QString FinishMoveData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void FinishMoveData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "duration")
        m_duration = readInt(field->getValue());
    
    else if(field->getName() == "free")
        m_free = readBool(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "category")
        m_category = readInt(field->getValue());
    
    else if(field->getName() == "spellLevel")
        m_spellLevel = readInt(field->getValue());
    
  }
}

