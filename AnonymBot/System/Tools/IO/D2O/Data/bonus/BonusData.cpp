#include "BonusData.h"

int BonusData::getId() const
{
  return m_id;
}

uint BonusData::getType() const
{
  return m_type;
}

int BonusData::getAmount() const
{
  return m_amount;
}

QList<int> BonusData::getCriterionsIds() const
{
  return m_criterionsIds;
}

void BonusData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "type")
        m_type = readUInt(field->getValue());
    
    else if(field->getName() == "amount")
        m_amount = readInt(field->getValue());
    
    else if(field->getName() == "criterionsIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_criterionsIds << readInt(data);
    }
    
  }
}

