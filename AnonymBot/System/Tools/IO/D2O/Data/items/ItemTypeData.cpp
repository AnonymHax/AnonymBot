#include "ItemTypeData.h"

int ItemTypeData::getId() const
{
  return m_id;
}

uint ItemTypeData::getNameId() const
{
  return m_nameId;
}

uint ItemTypeData::getSuperTypeId() const
{
  return m_superTypeId;
}

bool ItemTypeData::getPlural() const
{
  return m_plural;
}

uint ItemTypeData::getGender() const
{
  return m_gender;
}

QString ItemTypeData::getRawZone() const
{
  return m_rawZone;
}

bool ItemTypeData::getMimickable() const
{
  return m_mimickable;
}

int ItemTypeData::getCraftXpRatio() const
{
  return m_craftXpRatio;
}

QString ItemTypeData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void ItemTypeData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "superTypeId")
        m_superTypeId = readUInt(field->getValue());
    
    else if(field->getName() == "plural")
        m_plural = readBool(field->getValue());
    
    else if(field->getName() == "gender")
        m_gender = readUInt(field->getValue());
    
    else if(field->getName() == "rawZone")
        m_rawZone = readUTF(field->getValue());
    
    else if(field->getName() == "mimickable")
        m_mimickable = readBool(field->getValue());
    
    else if(field->getName() == "craftXpRatio")
        m_craftXpRatio = readInt(field->getValue());
    
  }
}

