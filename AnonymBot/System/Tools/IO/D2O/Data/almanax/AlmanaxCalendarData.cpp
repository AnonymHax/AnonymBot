#include "AlmanaxCalendarData.h"

int AlmanaxCalendarData::getId() const
{
  return m_id;
}

uint AlmanaxCalendarData::getNameId() const
{
  return m_nameId;
}

uint AlmanaxCalendarData::getDescId() const
{
  return m_descId;
}

int AlmanaxCalendarData::getNpcId() const
{
  return m_npcId;
}

QList<int> AlmanaxCalendarData::getBonusesIds() const
{
  return m_bonusesIds;
}

QString AlmanaxCalendarData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void AlmanaxCalendarData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "descId")
        m_descId = readUInt(field->getValue());
    
    else if(field->getName() == "npcId")
        m_npcId = readInt(field->getValue());
    
    else if(field->getName() == "bonusesIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_bonusesIds << readInt(data);
    }
    
  }
}

