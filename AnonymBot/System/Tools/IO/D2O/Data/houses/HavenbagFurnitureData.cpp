#include "HavenbagFurnitureData.h"

int HavenbagFurnitureData::getTypeId() const
{
  return m_typeId;
}

int HavenbagFurnitureData::getThemeId() const
{
  return m_themeId;
}

int HavenbagFurnitureData::getElementId() const
{
  return m_elementId;
}

int HavenbagFurnitureData::getColor() const
{
  return m_color;
}

int HavenbagFurnitureData::getSkillId() const
{
  return m_skillId;
}

int HavenbagFurnitureData::getLayerId() const
{
  return m_layerId;
}

bool HavenbagFurnitureData::getBlocksMovement() const
{
  return m_blocksMovement;
}

bool HavenbagFurnitureData::getIsStackable() const
{
  return m_isStackable;
}

uint HavenbagFurnitureData::getCellsWidth() const
{
  return m_cellsWidth;
}

uint HavenbagFurnitureData::getCellsHeight() const
{
  return m_cellsHeight;
}

uint HavenbagFurnitureData::getOrder() const
{
  return m_order;
}

void HavenbagFurnitureData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "typeId")
        m_typeId = readInt(field->getValue());
    
    else if(field->getName() == "themeId")
        m_themeId = readInt(field->getValue());
    
    else if(field->getName() == "elementId")
        m_elementId = readInt(field->getValue());
    
    else if(field->getName() == "color")
        m_color = readInt(field->getValue());
    
    else if(field->getName() == "skillId")
        m_skillId = readInt(field->getValue());
    
    else if(field->getName() == "layerId")
        m_layerId = readInt(field->getValue());
    
    else if(field->getName() == "blocksMovement")
        m_blocksMovement = readBool(field->getValue());
    
    else if(field->getName() == "isStackable")
        m_isStackable = readBool(field->getValue());
    
    else if(field->getName() == "cellsWidth")
        m_cellsWidth = readUInt(field->getValue());
    
    else if(field->getName() == "cellsHeight")
        m_cellsHeight = readUInt(field->getValue());
    
    else if(field->getName() == "order")
        m_order = readUInt(field->getValue());
    
  }
}

