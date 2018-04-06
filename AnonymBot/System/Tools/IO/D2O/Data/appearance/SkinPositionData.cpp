#include "SkinPositionData.h"

uint SkinPositionData::getId() const
{
  return m_id;
}

QList<QString> SkinPositionData::getClip() const
{
  return m_clip;
}

QList<uint> SkinPositionData::getSkin() const
{
  return m_skin;
}

void SkinPositionData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "clip")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_clip << readUTF(data);
    }
    
    else if(field->getName() == "skin")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_skin << readUInt(data);
    }
    
  }
}

