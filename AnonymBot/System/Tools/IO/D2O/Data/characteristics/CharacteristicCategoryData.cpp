#include "CharacteristicCategoryData.h"

int CharacteristicCategoryData::getId() const
{
  return m_id;
}

uint CharacteristicCategoryData::getNameId() const
{
  return m_nameId;
}

int CharacteristicCategoryData::getOrder() const
{
  return m_order;
}

QList<uint> CharacteristicCategoryData::getCharacteristicIds() const
{
  return m_characteristicIds;
}

QString CharacteristicCategoryData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void CharacteristicCategoryData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "order")
        m_order = readInt(field->getValue());
    
    else if(field->getName() == "characteristicIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_characteristicIds << readUInt(data);
    }
    
  }
}

