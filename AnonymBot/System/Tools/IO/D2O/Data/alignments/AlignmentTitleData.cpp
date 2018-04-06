#include "AlignmentTitleData.h"

int AlignmentTitleData::getSideId() const
{
  return m_sideId;
}

QList<int> AlignmentTitleData::getNamesId() const
{
  return m_namesId;
}

QList<int> AlignmentTitleData::getShortsId() const
{
  return m_shortsId;
}

void AlignmentTitleData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "sideId")
        m_sideId = readInt(field->getValue());
    
    else if(field->getName() == "namesId")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_namesId << readInt(data);
    }
    
    else if(field->getName() == "shortsId")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_shortsId << readInt(data);
    }
    
  }
}

