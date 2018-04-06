#include "PlaylistSoundData.h"

QString PlaylistSoundData::getId() const
{
  return m_id;
}

int PlaylistSoundData::getVolume() const
{
  return m_volume;
}

int PlaylistSoundData::getChannel() const
{
  return m_channel;
}

void PlaylistSoundData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUTF(field->getValue());
    
    else if(field->getName() == "volume")
        m_volume = readInt(field->getValue());
    
    else if(field->getName() == "channel")
        m_channel = readInt(field->getValue());
    
  }
}

