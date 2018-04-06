#include "SoundAnimationData.h"

QString SoundAnimationData::getMODULE() const
{
  return m_MODULE;
}

uint SoundAnimationData::getId() const
{
  return m_id;
}

QString SoundAnimationData::getName() const
{
  return m_name;
}

QString SoundAnimationData::getLabel() const
{
  return m_label;
}

QString SoundAnimationData::getFilename() const
{
  return m_filename;
}

int SoundAnimationData::getVolume() const
{
  return m_volume;
}

int SoundAnimationData::getRolloff() const
{
  return m_rolloff;
}

int SoundAnimationData::getAutomationDuration() const
{
  return m_automationDuration;
}

int SoundAnimationData::getAutomationVolume() const
{
  return m_automationVolume;
}

int SoundAnimationData::getAutomationFadeIn() const
{
  return m_automationFadeIn;
}

int SoundAnimationData::getAutomationFadeOut() const
{
  return m_automationFadeOut;
}

bool SoundAnimationData::getNoCutSilence() const
{
  return m_noCutSilence;
}

uint SoundAnimationData::getStartFrame() const
{
  return m_startFrame;
}

void SoundAnimationData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "MODULE")
        m_MODULE = readUTF(field->getValue());
    
    else if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "name")
        m_name = readUTF(field->getValue());
    
    else if(field->getName() == "label")
        m_label = readUTF(field->getValue());
    
    else if(field->getName() == "filename")
        m_filename = readUTF(field->getValue());
    
    else if(field->getName() == "volume")
        m_volume = readInt(field->getValue());
    
    else if(field->getName() == "rolloff")
        m_rolloff = readInt(field->getValue());
    
    else if(field->getName() == "automationDuration")
        m_automationDuration = readInt(field->getValue());
    
    else if(field->getName() == "automationVolume")
        m_automationVolume = readInt(field->getValue());
    
    else if(field->getName() == "automationFadeIn")
        m_automationFadeIn = readInt(field->getValue());
    
    else if(field->getName() == "automationFadeOut")
        m_automationFadeOut = readInt(field->getValue());
    
    else if(field->getName() == "noCutSilence")
        m_noCutSilence = readBool(field->getValue());
    
    else if(field->getName() == "startFrame")
        m_startFrame = readUInt(field->getValue());
    
  }
}

