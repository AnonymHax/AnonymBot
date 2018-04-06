#include "HouseData.h"

int HouseData::getTypeId() const
{
  return m_typeId;
}

uint HouseData::getDefaultPrice() const
{
  return m_defaultPrice;
}

int HouseData::getNameId() const
{
  return m_nameId;
}

int HouseData::getDescriptionId() const
{
  return m_descriptionId;
}

int HouseData::getGfxId() const
{
  return m_gfxId;
}

QString HouseData::getName() const
{
  return m_I18n->getText(m_nameId);
}

QString HouseData::getDescription() const
{
  return m_I18n->getText(m_descriptionId);
}

void HouseData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "typeId")
        m_typeId = readInt(field->getValue());
    
    else if(field->getName() == "defaultPrice")
        m_defaultPrice = readUInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readInt(field->getValue());
    
    else if(field->getName() == "descriptionId")
        m_descriptionId = readInt(field->getValue());
    
    else if(field->getName() == "gfxId")
        m_gfxId = readInt(field->getValue());
    
  }
}

