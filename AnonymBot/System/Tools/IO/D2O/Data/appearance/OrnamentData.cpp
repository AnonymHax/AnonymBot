#include "OrnamentData.h"

int OrnamentData::getId() const
{
  return m_id;
}

uint OrnamentData::getNameId() const
{
  return m_nameId;
}

bool OrnamentData::getVisible() const
{
  return m_visible;
}

int OrnamentData::getAssetId() const
{
  return m_assetId;
}

int OrnamentData::getIconId() const
{
  return m_iconId;
}

int OrnamentData::getRarity() const
{
  return m_rarity;
}

int OrnamentData::getOrder() const
{
  return m_order;
}

QString OrnamentData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void OrnamentData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "visible")
        m_visible = readBool(field->getValue());
    
    else if(field->getName() == "assetId")
        m_assetId = readInt(field->getValue());
    
    else if(field->getName() == "iconId")
        m_iconId = readInt(field->getValue());
    
    else if(field->getName() == "rarity")
        m_rarity = readInt(field->getValue());
    
    else if(field->getName() == "order")
        m_order = readInt(field->getValue());
    
  }
}

