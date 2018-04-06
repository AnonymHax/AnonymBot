#include "CharacteristicData.h"

int CharacteristicData::getId() const
{
  return m_id;
}

QString CharacteristicData::getKeyword() const
{
  return m_keyword;
}

uint CharacteristicData::getNameId() const
{
  return m_nameId;
}

QString CharacteristicData::getAsset() const
{
  return m_asset;
}

int CharacteristicData::getCategoryId() const
{
  return m_categoryId;
}

bool CharacteristicData::getVisible() const
{
  return m_visible;
}

int CharacteristicData::getOrder() const
{
  return m_order;
}

bool CharacteristicData::getUpgradable() const
{
  return m_upgradable;
}

QString CharacteristicData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void CharacteristicData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "keyword")
        m_keyword = readUTF(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "asset")
        m_asset = readUTF(field->getValue());
    
    else if(field->getName() == "categoryId")
        m_categoryId = readInt(field->getValue());
    
    else if(field->getName() == "visible")
        m_visible = readBool(field->getValue());
    
    else if(field->getName() == "order")
        m_order = readInt(field->getValue());
    
    else if(field->getName() == "upgradable")
        m_upgradable = readBool(field->getValue());
    
  }
}

