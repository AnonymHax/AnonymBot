#include "SpellStateData.h"

int SpellStateData::getId() const
{
  return m_id;
}

uint SpellStateData::getNameId() const
{
  return m_nameId;
}

bool SpellStateData::getPreventsSpellCast() const
{
  return m_preventsSpellCast;
}

bool SpellStateData::getPreventsFight() const
{
  return m_preventsFight;
}

bool SpellStateData::getIsSilent() const
{
  return m_isSilent;
}

bool SpellStateData::getCantDealDamage() const
{
  return m_cantDealDamage;
}

bool SpellStateData::getInvulnerable() const
{
  return m_invulnerable;
}

bool SpellStateData::getIncurable() const
{
  return m_incurable;
}

bool SpellStateData::getCantBeMoved() const
{
  return m_cantBeMoved;
}

bool SpellStateData::getCantBePushed() const
{
  return m_cantBePushed;
}

bool SpellStateData::getCantSwitchPosition() const
{
  return m_cantSwitchPosition;
}

QList<int> SpellStateData::getEffectsIds() const
{
  return m_effectsIds;
}

QString SpellStateData::getIcon() const
{
  return m_icon;
}

int SpellStateData::getIconVisibilityMask() const
{
  return m_iconVisibilityMask;
}

bool SpellStateData::getInvulnerableMelee() const
{
  return m_invulnerableMelee;
}

bool SpellStateData::getInvulnerableRange() const
{
  return m_invulnerableRange;
}

QString SpellStateData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void SpellStateData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "preventsSpellCast")
        m_preventsSpellCast = readBool(field->getValue());
    
    else if(field->getName() == "preventsFight")
        m_preventsFight = readBool(field->getValue());
    
    else if(field->getName() == "isSilent")
        m_isSilent = readBool(field->getValue());
    
    else if(field->getName() == "cantDealDamage")
        m_cantDealDamage = readBool(field->getValue());
    
    else if(field->getName() == "invulnerable")
        m_invulnerable = readBool(field->getValue());
    
    else if(field->getName() == "incurable")
        m_incurable = readBool(field->getValue());
    
    else if(field->getName() == "cantBeMoved")
        m_cantBeMoved = readBool(field->getValue());
    
    else if(field->getName() == "cantBePushed")
        m_cantBePushed = readBool(field->getValue());
    
    else if(field->getName() == "cantSwitchPosition")
        m_cantSwitchPosition = readBool(field->getValue());
    
    else if(field->getName() == "effectsIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_effectsIds << readInt(data);
    }
    
    else if(field->getName() == "icon")
        m_icon = readUTF(field->getValue());
    
    else if(field->getName() == "iconVisibilityMask")
        m_iconVisibilityMask = readInt(field->getValue());
    
    else if(field->getName() == "invulnerableMelee")
        m_invulnerableMelee = readBool(field->getValue());
    
    else if(field->getName() == "invulnerableRange")
        m_invulnerableRange = readBool(field->getValue());
    
  }
}

