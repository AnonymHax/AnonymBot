#include "HeadData.h"

int HeadData::getId() const
{
  return m_id;
}

QString HeadData::getSkins() const
{
  return m_skins;
}

QString HeadData::getAssetId() const
{
  return m_assetId;
}

uint HeadData::getBreed() const
{
  return m_breed;
}

uint HeadData::getGender() const
{
  return m_gender;
}

QString HeadData::getLabel() const
{
  return m_label;
}

uint HeadData::getOrder() const
{
  return m_order;
}

void HeadData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "skins")
        m_skins = readUTF(field->getValue());
    
    else if(field->getName() == "assetId")
        m_assetId = readUTF(field->getValue());
    
    else if(field->getName() == "breed")
        m_breed = readUInt(field->getValue());
    
    else if(field->getName() == "gender")
        m_gender = readUInt(field->getValue());
    
    else if(field->getName() == "label")
        m_label = readUTF(field->getValue());
    
    else if(field->getName() == "order")
        m_order = readUInt(field->getValue());
    
  }
}

