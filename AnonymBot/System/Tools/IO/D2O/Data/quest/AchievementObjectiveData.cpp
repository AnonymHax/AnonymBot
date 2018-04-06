#include "AchievementObjectiveData.h"

uint AchievementObjectiveData::getId() const
{
  return m_id;
}

uint AchievementObjectiveData::getAchievementId() const
{
  return m_achievementId;
}

uint AchievementObjectiveData::getOrder() const
{
  return m_order;
}

uint AchievementObjectiveData::getNameId() const
{
  return m_nameId;
}

QString AchievementObjectiveData::getCriterion() const
{
  return m_criterion;
}

QString AchievementObjectiveData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void AchievementObjectiveData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "achievementId")
        m_achievementId = readUInt(field->getValue());
    
    else if(field->getName() == "order")
        m_order = readUInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "criterion")
        m_criterion = readUTF(field->getValue());
    
  }
}

