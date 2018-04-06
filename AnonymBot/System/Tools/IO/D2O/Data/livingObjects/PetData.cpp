#include "PetData.h"

int PetData::getId() const
{
  return m_id;
}

QList<int> PetData::getFoodItems() const
{
  return m_foodItems;
}

QList<int> PetData::getFoodTypes() const
{
  return m_foodTypes;
}

int PetData::getMinDurationBeforeMeal() const
{
  return m_minDurationBeforeMeal;
}

int PetData::getMaxDurationBeforeMeal() const
{
  return m_maxDurationBeforeMeal;
}

QList<EffectInstanceData> PetData::getPossibleEffects() const
{
  return m_possibleEffects;
}

void PetData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "foodItems")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_foodItems << readInt(data);
    }
    
    else if(field->getName() == "foodTypes")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_foodTypes << readInt(data);
    }
    
    else if(field->getName() == "minDurationBeforeMeal")
        m_minDurationBeforeMeal = readInt(field->getValue());
    
    else if(field->getName() == "maxDurationBeforeMeal")
        m_maxDurationBeforeMeal = readInt(field->getValue());
    
    else if(field->getName() == "possibleEffects")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_possibleEffects << *qSharedPointerCast<EffectInstanceData>(readObject(data, field)).data();
    }
    
  }
}

