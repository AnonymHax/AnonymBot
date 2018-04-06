#include "SoundUiElementData.h"

QString SoundUiElementData::getMODULE() const
{
  return m_MODULE;
}

uint SoundUiElementData::getId() const
{
  return m_id;
}

QString SoundUiElementData::getName() const
{
  return m_name;
}

uint SoundUiElementData::getHookId() const
{
  return m_hookId;
}

QString SoundUiElementData::getFile() const
{
  return m_file;
}

uint SoundUiElementData::getVolume() const
{
  return m_volume;
}

void SoundUiElementData::loadData(const QList<Field*> &fields, I18nFile *I18n)
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
    
    else if(field->getName() == "hookId")
        m_hookId = readUInt(field->getValue());
    
    else if(field->getName() == "file")
        m_file = readUTF(field->getValue());
    
    else if(field->getName() == "volume")
        m_volume = readUInt(field->getValue());
    
  }
}

