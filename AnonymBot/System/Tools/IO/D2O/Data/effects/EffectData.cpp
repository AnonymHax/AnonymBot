#include "EffectData.h"

int EffectData::getId() const
{
  return m_id;
}

uint EffectData::getDescriptionId() const
{
  return m_descriptionId;
}

uint EffectData::getIconId() const
{
  return m_iconId;
}

int EffectData::getCharacteristic() const
{
  return m_characteristic;
}

uint EffectData::getCategory() const
{
  return m_category;
}

QString EffectData::getOperator() const
{
  return m_operator;
}

bool EffectData::getShowInTooltip() const
{
  return m_showInTooltip;
}

bool EffectData::getUseDice() const
{
  return m_useDice;
}

bool EffectData::getForceMinMax() const
{
  return m_forceMinMax;
}

bool EffectData::getBoost() const
{
  return m_boost;
}

bool EffectData::getActive() const
{
  return m_active;
}

int EffectData::getOppositeId() const
{
  return m_oppositeId;
}

uint EffectData::getTheoreticalDescriptionId() const
{
  return m_theoreticalDescriptionId;
}

uint EffectData::getTheoreticalPattern() const
{
  return m_theoreticalPattern;
}

bool EffectData::getShowInSet() const
{
  return m_showInSet;
}

int EffectData::getBonusType() const
{
  return m_bonusType;
}

bool EffectData::getUseInFight() const
{
  return m_useInFight;
}

uint EffectData::getEffectPriority() const
{
  return m_effectPriority;
}

int EffectData::getElementId() const
{
  return m_elementId;
}

QString EffectData::getDescription() const
{
  return m_I18n->getText(m_descriptionId);
}

void EffectData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "descriptionId")
        m_descriptionId = readUInt(field->getValue());
    
    else if(field->getName() == "iconId")
        m_iconId = readUInt(field->getValue());
    
    else if(field->getName() == "characteristic")
        m_characteristic = readInt(field->getValue());
    
    else if(field->getName() == "category")
        m_category = readUInt(field->getValue());
    
    else if(field->getName() == "operator")
        m_operator = readUTF(field->getValue());
    
    else if(field->getName() == "showInTooltip")
        m_showInTooltip = readBool(field->getValue());
    
    else if(field->getName() == "useDice")
        m_useDice = readBool(field->getValue());
    
    else if(field->getName() == "forceMinMax")
        m_forceMinMax = readBool(field->getValue());
    
    else if(field->getName() == "boost")
        m_boost = readBool(field->getValue());
    
    else if(field->getName() == "active")
        m_active = readBool(field->getValue());
    
    else if(field->getName() == "oppositeId")
        m_oppositeId = readInt(field->getValue());
    
    else if(field->getName() == "theoreticalDescriptionId")
        m_theoreticalDescriptionId = readUInt(field->getValue());
    
    else if(field->getName() == "theoreticalPattern")
        m_theoreticalPattern = readUInt(field->getValue());
    
    else if(field->getName() == "showInSet")
        m_showInSet = readBool(field->getValue());
    
    else if(field->getName() == "bonusType")
        m_bonusType = readInt(field->getValue());
    
    else if(field->getName() == "useInFight")
        m_useInFight = readBool(field->getValue());
    
    else if(field->getName() == "effectPriority")
        m_effectPriority = readUInt(field->getValue());
    
    else if(field->getName() == "elementId")
        m_elementId = readInt(field->getValue());
    
  }
}

