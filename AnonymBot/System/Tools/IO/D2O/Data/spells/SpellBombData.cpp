#include "SpellBombData.h"

int SpellBombData::getId() const
{
  return m_id;
}

int SpellBombData::getChainReactionSpellId() const
{
  return m_chainReactionSpellId;
}

int SpellBombData::getExplodSpellId() const
{
  return m_explodSpellId;
}

int SpellBombData::getWallId() const
{
  return m_wallId;
}

int SpellBombData::getInstantSpellId() const
{
  return m_instantSpellId;
}

int SpellBombData::getComboCoeff() const
{
  return m_comboCoeff;
}

void SpellBombData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "chainReactionSpellId")
        m_chainReactionSpellId = readInt(field->getValue());
    
    else if(field->getName() == "explodSpellId")
        m_explodSpellId = readInt(field->getValue());
    
    else if(field->getName() == "wallId")
        m_wallId = readInt(field->getValue());
    
    else if(field->getName() == "instantSpellId")
        m_instantSpellId = readInt(field->getValue());
    
    else if(field->getName() == "comboCoeff")
        m_comboCoeff = readInt(field->getValue());
    
  }
}

