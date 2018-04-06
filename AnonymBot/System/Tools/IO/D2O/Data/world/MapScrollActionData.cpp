#include "MapScrollActionData.h"

int MapScrollActionData::getId() const
{
  return m_id;
}

bool MapScrollActionData::getRightExists() const
{
  return m_rightExists;
}

bool MapScrollActionData::getBottomExists() const
{
  return m_bottomExists;
}

bool MapScrollActionData::getLeftExists() const
{
  return m_leftExists;
}

bool MapScrollActionData::getTopExists() const
{
  return m_topExists;
}

int MapScrollActionData::getRightMapId() const
{
  return m_rightMapId;
}

int MapScrollActionData::getBottomMapId() const
{
  return m_bottomMapId;
}

int MapScrollActionData::getLeftMapId() const
{
  return m_leftMapId;
}

int MapScrollActionData::getTopMapId() const
{
  return m_topMapId;
}

void MapScrollActionData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "rightExists")
        m_rightExists = readBool(field->getValue());
    
    else if(field->getName() == "bottomExists")
        m_bottomExists = readBool(field->getValue());
    
    else if(field->getName() == "leftExists")
        m_leftExists = readBool(field->getValue());
    
    else if(field->getName() == "topExists")
        m_topExists = readBool(field->getValue());
    
    else if(field->getName() == "rightMapId")
        m_rightMapId = readInt(field->getValue());
    
    else if(field->getName() == "bottomMapId")
        m_bottomMapId = readInt(field->getValue());
    
    else if(field->getName() == "leftMapId")
        m_leftMapId = readInt(field->getValue());
    
    else if(field->getName() == "topMapId")
        m_topMapId = readInt(field->getValue());
    
  }
}

