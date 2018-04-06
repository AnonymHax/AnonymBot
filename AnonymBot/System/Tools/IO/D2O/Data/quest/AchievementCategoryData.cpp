#include "AchievementCategoryData.h"

uint AchievementCategoryData::getId() const
{
  return m_id;
}

uint AchievementCategoryData::getNameId() const
{
  return m_nameId;
}

uint AchievementCategoryData::getParentId() const
{
  return m_parentId;
}

QString AchievementCategoryData::getIcon() const
{
  return m_icon;
}

uint AchievementCategoryData::getOrder() const
{
  return m_order;
}

QString AchievementCategoryData::getColor() const
{
  return m_color;
}

QList<uint> AchievementCategoryData::getAchievementIds() const
{
  return m_achievementIds;
}

QString AchievementCategoryData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void AchievementCategoryData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "parentId")
        m_parentId = readUInt(field->getValue());
    
    else if(field->getName() == "icon")
        m_icon = readUTF(field->getValue());
    
    else if(field->getName() == "order")
        m_order = readUInt(field->getValue());
    
    else if(field->getName() == "color")
        m_color = readUTF(field->getValue());
    
    else if(field->getName() == "achievementIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_achievementIds << readUInt(data);
    }
    
  }
}

