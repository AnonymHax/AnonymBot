#include "SoundBonesData.h"

QString SoundBonesData::getMODULE() const
{
  return m_MODULE;
}

uint SoundBonesData::getId() const
{
  return m_id;
}

QList<QString> SoundBonesData::getKeys() const
{
  return m_keys;
}

QList<QList<SoundAnimationData>> SoundBonesData::getValues() const
{
  return m_values;
}

void SoundBonesData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "MODULE")
        m_MODULE = readUTF(field->getValue());
    
    else if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "keys")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_keys << readUTF(data);
    }
    
    else if(field->getName() == "values")
    {
      foreach(const QByteArray &firstList, readVector(field->getValue()))
      {
        QList<SoundAnimationData> secondList;
        
        foreach (const QByteArray &data, readVector(firstList))
            secondList << *qSharedPointerCast<SoundAnimationData>(readObject(data, field)).data();
        
        m_values << secondList;
      }
    }
    
  }
}

