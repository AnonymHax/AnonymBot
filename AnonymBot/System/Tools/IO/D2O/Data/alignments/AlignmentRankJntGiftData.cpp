#include "AlignmentRankJntGiftData.h"

int AlignmentRankJntGiftData::getId() const
{
  return m_id;
}

QList<int> AlignmentRankJntGiftData::getGifts() const
{
  return m_gifts;
}

QList<int> AlignmentRankJntGiftData::getParameters() const
{
  return m_parameters;
}

QList<int> AlignmentRankJntGiftData::getLevels() const
{
  return m_levels;
}

void AlignmentRankJntGiftData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "gifts")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_gifts << readInt(data);
    }
    
    else if(field->getName() == "parameters")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_parameters << readInt(data);
    }
    
    else if(field->getName() == "levels")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_levels << readInt(data);
    }
    
  }
}

