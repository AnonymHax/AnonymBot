#include "SpeakingItemTextData.h"

int SpeakingItemTextData::getTextId() const
{
  return m_textId;
}

double SpeakingItemTextData::getTextProba() const
{
  return m_textProba;
}

uint SpeakingItemTextData::getTextStringId() const
{
  return m_textStringId;
}

int SpeakingItemTextData::getTextLevel() const
{
  return m_textLevel;
}

int SpeakingItemTextData::getTextSound() const
{
  return m_textSound;
}

QString SpeakingItemTextData::getTextRestriction() const
{
  return m_textRestriction;
}

QString SpeakingItemTextData::getTextString() const
{
  return m_I18n->getText(m_textStringId);
}

void SpeakingItemTextData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "textId")
        m_textId = readInt(field->getValue());
    
    else if(field->getName() == "textProba")
        m_textProba = readDouble(field->getValue());
    
    else if(field->getName() == "textStringId")
        m_textStringId = readUInt(field->getValue());
    
    else if(field->getName() == "textLevel")
        m_textLevel = readInt(field->getValue());
    
    else if(field->getName() == "textSound")
        m_textSound = readInt(field->getValue());
    
    else if(field->getName() == "textRestriction")
        m_textRestriction = readUTF(field->getValue());
    
  }
}

