#include "EmblemSymbolData.h"

int EmblemSymbolData::getId() const
{
  return m_id;
}

int EmblemSymbolData::getIconId() const
{
  return m_iconId;
}

int EmblemSymbolData::getSkinId() const
{
  return m_skinId;
}

int EmblemSymbolData::getOrder() const
{
  return m_order;
}

int EmblemSymbolData::getCategoryId() const
{
  return m_categoryId;
}

bool EmblemSymbolData::getColorizable() const
{
  return m_colorizable;
}

void EmblemSymbolData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "iconId")
        m_iconId = readInt(field->getValue());
    
    else if(field->getName() == "skinId")
        m_skinId = readInt(field->getValue());
    
    else if(field->getName() == "order")
        m_order = readInt(field->getValue());
    
    else if(field->getName() == "categoryId")
        m_categoryId = readInt(field->getValue());
    
    else if(field->getName() == "colorizable")
        m_colorizable = readBool(field->getValue());
    
  }
}

