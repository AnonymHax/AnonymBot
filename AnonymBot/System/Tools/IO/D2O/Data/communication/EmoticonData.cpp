#include "EmoticonData.h"

uint EmoticonData::getId() const
{
  return m_id;
}

uint EmoticonData::getNameId() const
{
  return m_nameId;
}

uint EmoticonData::getShortcutId() const
{
  return m_shortcutId;
}

uint EmoticonData::getOrder() const
{
  return m_order;
}

QString EmoticonData::getDefaultAnim() const
{
  return m_defaultAnim;
}

bool EmoticonData::getPersistancy() const
{
  return m_persistancy;
}

bool EmoticonData::getAura() const
{
  return m_aura;
}

QList<QString> EmoticonData::getAnims() const
{
  return m_anims;
}

uint EmoticonData::getCooldown() const
{
  return m_cooldown;
}

uint EmoticonData::getDuration() const
{
  return m_duration;
}

uint EmoticonData::getWeight() const
{
  return m_weight;
}

QString EmoticonData::getName() const
{
  return m_I18n->getText(m_nameId);
}

QString EmoticonData::getShortcut() const
{
  return m_I18n->getText(m_shortcutId);
}

void EmoticonData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "shortcutId")
        m_shortcutId = readUInt(field->getValue());
    
    else if(field->getName() == "order")
        m_order = readUInt(field->getValue());
    
    else if(field->getName() == "defaultAnim")
        m_defaultAnim = readUTF(field->getValue());
    
    else if(field->getName() == "persistancy")
        m_persistancy = readBool(field->getValue());
    
    else if(field->getName() == "aura")
        m_aura = readBool(field->getValue());
    
    else if(field->getName() == "anims")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_anims << readUTF(data);
    }
    
    else if(field->getName() == "cooldown")
        m_cooldown = readUInt(field->getValue());
    
    else if(field->getName() == "duration")
        m_duration = readUInt(field->getValue());
    
    else if(field->getName() == "weight")
        m_weight = readUInt(field->getValue());
    
  }
}

