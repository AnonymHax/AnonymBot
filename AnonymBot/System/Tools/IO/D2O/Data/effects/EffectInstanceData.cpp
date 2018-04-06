#include "EffectInstanceData.h"

uint EffectInstanceData::getEffectUid() const
{
  return m_effectUid;
}

uint EffectInstanceData::getEffectId() const
{
  return m_effectId;
}

int EffectInstanceData::getTargetId() const
{
  return m_targetId;
}

QString EffectInstanceData::getTargetMask() const
{
  return m_targetMask;
}

int EffectInstanceData::getDuration() const
{
  return m_duration;
}

int EffectInstanceData::getDelay() const
{
  return m_delay;
}

int EffectInstanceData::getRandom() const
{
  return m_random;
}

int EffectInstanceData::getGroup() const
{
  return m_group;
}

int EffectInstanceData::getModificator() const
{
  return m_modificator;
}

bool EffectInstanceData::getTrigger() const
{
  return m_trigger;
}

QString EffectInstanceData::getTriggers() const
{
  return m_triggers;
}

bool EffectInstanceData::getVisibleInTooltip() const
{
  return m_visibleInTooltip;
}

bool EffectInstanceData::getVisibleInBuffUi() const
{
  return m_visibleInBuffUi;
}

bool EffectInstanceData::getVisibleInFightLog() const
{
  return m_visibleInFightLog;
}

uint EffectInstanceData::getZoneShape() const
{
  return m_zoneShape;
}

int EffectInstanceData::getEffectElement() const
{
  return m_effectElement;
}

void EffectInstanceData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "effectUid")
        m_effectUid = readUInt(field->getValue());
    
    else if(field->getName() == "effectId")
        m_effectId = readUInt(field->getValue());
    
    else if(field->getName() == "targetId")
        m_targetId = readInt(field->getValue());
    
    else if(field->getName() == "targetMask")
        m_targetMask = readUTF(field->getValue());
    
    else if(field->getName() == "duration")
        m_duration = readInt(field->getValue());
    
    else if(field->getName() == "delay")
        m_delay = readInt(field->getValue());
    
    else if(field->getName() == "random")
        m_random = readInt(field->getValue());
    
    else if(field->getName() == "group")
        m_group = readInt(field->getValue());
    
    else if(field->getName() == "modificator")
        m_modificator = readInt(field->getValue());
    
    else if(field->getName() == "trigger")
        m_trigger = readBool(field->getValue());
    
    else if(field->getName() == "triggers")
        m_triggers = readUTF(field->getValue());
    
    else if(field->getName() == "visibleInTooltip")
        m_visibleInTooltip = readBool(field->getValue());
    
    else if(field->getName() == "visibleInBuffUi")
        m_visibleInBuffUi = readBool(field->getValue());
    
    else if(field->getName() == "visibleInFightLog")
        m_visibleInFightLog = readBool(field->getValue());
    
    else if(field->getName() == "zoneShape")
        m_zoneShape = readUInt(field->getValue());
    
    else if(field->getName() == "effectElement")
        m_effectElement = readInt(field->getValue());
    
  }
}

