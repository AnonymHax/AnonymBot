#include "BreedRoleByBreedData.h"

int BreedRoleByBreedData::getBreedId() const
{
  return m_breedId;
}

int BreedRoleByBreedData::getRoleId() const
{
  return m_roleId;
}

uint BreedRoleByBreedData::getDescriptionId() const
{
  return m_descriptionId;
}

int BreedRoleByBreedData::getValue() const
{
  return m_value;
}

int BreedRoleByBreedData::getOrder() const
{
  return m_order;
}

QString BreedRoleByBreedData::getDescription() const
{
  return m_I18n->getText(m_descriptionId);
}

void BreedRoleByBreedData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "breedId")
        m_breedId = readInt(field->getValue());
    
    else if(field->getName() == "roleId")
        m_roleId = readInt(field->getValue());
    
    else if(field->getName() == "descriptionId")
        m_descriptionId = readUInt(field->getValue());
    
    else if(field->getName() == "value")
        m_value = readInt(field->getValue());
    
    else if(field->getName() == "order")
        m_order = readInt(field->getValue());
    
  }
}

