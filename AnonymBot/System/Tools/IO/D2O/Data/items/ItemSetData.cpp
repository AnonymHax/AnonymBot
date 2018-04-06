#include "ItemSetData.h"

uint ItemSetData::getId() const
{
  return m_id;
}

QList<uint> ItemSetData::getItems() const
{
  return m_items;
}

uint ItemSetData::getNameId() const
{
  return m_nameId;
}

QList<QList<EffectInstanceData>> ItemSetData::getEffects() const
{
  return m_effects;
}

bool ItemSetData::getBonusIsSecret() const
{
  return m_bonusIsSecret;
}

QString ItemSetData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void ItemSetData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "items")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_items << readUInt(data);
    }
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "effects")
    {
      foreach(const QByteArray &firstList, readVector(field->getValue()))
      {
        QList<EffectInstanceData> secondList;
        
        foreach (const QByteArray &data, readVector(firstList))
            secondList << *qSharedPointerCast<EffectInstanceData>(readObject(data, field)).data();
        
        m_effects << secondList;
      }
    }
    
    else if(field->getName() == "bonusIsSecret")
        m_bonusIsSecret = readBool(field->getValue());
    
  }
}

