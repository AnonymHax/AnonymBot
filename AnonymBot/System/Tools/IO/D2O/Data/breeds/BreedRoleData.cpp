#include "BreedRoleData.h"

int BreedRoleData::getId() const
{
  return m_id;
}

uint BreedRoleData::getNameId() const
{
  return m_nameId;
}

uint BreedRoleData::getDescriptionId() const
{
  return m_descriptionId;
}

int BreedRoleData::getAssetId() const
{
  return m_assetId;
}

int BreedRoleData::getColor() const
{
  return m_color;
}

QString BreedRoleData::getName() const
{
  return m_I18n->getText(m_nameId);
}

QString BreedRoleData::getDescription() const
{
  return m_I18n->getText(m_descriptionId);
}

void BreedRoleData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "descriptionId")
        m_descriptionId = readUInt(field->getValue());
    
    else if(field->getName() == "assetId")
        m_assetId = readInt(field->getValue());
    
    else if(field->getName() == "color")
        m_color = readInt(field->getValue());
    
  }
}

