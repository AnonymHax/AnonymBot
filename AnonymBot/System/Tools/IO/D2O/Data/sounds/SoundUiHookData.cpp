#include "SoundUiHookData.h"

QString SoundUiHookData::getMODULE() const
{
  return m_MODULE;
}

uint SoundUiHookData::getId() const
{
  return m_id;
}

QString SoundUiHookData::getName() const
{
  return m_name;
}

void SoundUiHookData::loadData(const QList<Field*> &fields, I18nFile *I18n)
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
    
  }
}

