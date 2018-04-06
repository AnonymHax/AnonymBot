#include "PlaylistData.h"

int PlaylistData::getId() const
{
  return m_id;
}

int PlaylistData::getSilenceDuration() const
{
  return m_silenceDuration;
}

int PlaylistData::getIteration() const
{
  return m_iteration;
}

int PlaylistData::getType() const
{
  return m_type;
}

QList<PlaylistSoundData> PlaylistData::getSounds() const
{
  return m_sounds;
}

void PlaylistData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "silenceDuration")
        m_silenceDuration = readInt(field->getValue());
    
    else if(field->getName() == "iteration")
        m_iteration = readInt(field->getValue());
    
    else if(field->getName() == "type")
        m_type = readInt(field->getValue());
    
    else if(field->getName() == "sounds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_sounds << *qSharedPointerCast<PlaylistSoundData>(readObject(data, field)).data();
    }
    
  }
}

