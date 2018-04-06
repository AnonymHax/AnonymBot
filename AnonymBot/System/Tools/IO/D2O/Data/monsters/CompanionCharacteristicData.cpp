#include "CompanionCharacteristicData.h"

int CompanionCharacteristicData::getId() const
{
  return m_id;
}

int CompanionCharacteristicData::getCaracId() const
{
  return m_caracId;
}

int CompanionCharacteristicData::getCompanionId() const
{
  return m_companionId;
}

int CompanionCharacteristicData::getOrder() const
{
  return m_order;
}

QList<QList<double>> CompanionCharacteristicData::getStatPerLevelRange() const
{
  return m_statPerLevelRange;
}

void CompanionCharacteristicData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "caracId")
        m_caracId = readInt(field->getValue());
    
    else if(field->getName() == "companionId")
        m_companionId = readInt(field->getValue());
    
    else if(field->getName() == "order")
        m_order = readInt(field->getValue());
    
    else if(field->getName() == "statPerLevelRange")
    {
      foreach(const QByteArray &firstList, readVector(field->getValue()))
      {
        QList<double> secondList;
        
        foreach (const QByteArray &data, readVector(firstList))
            secondList << readDouble(data);
        
        m_statPerLevelRange << secondList;
      }
    }
    
  }
}

