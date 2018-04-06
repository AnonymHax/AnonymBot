#include "AlignmentGiftData.h"

int AlignmentGiftData::getId() const
{
  return m_id;
}

uint AlignmentGiftData::getNameId() const
{
  return m_nameId;
}

int AlignmentGiftData::getEffectId() const
{
  return m_effectId;
}

uint AlignmentGiftData::getGfxId() const
{
  return m_gfxId;
}

QString AlignmentGiftData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void AlignmentGiftData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "effectId")
        m_effectId = readInt(field->getValue());
    
    else if(field->getName() == "gfxId")
        m_gfxId = readUInt(field->getValue());
    
  }
}

