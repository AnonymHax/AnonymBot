#include "QuestCategoryData.h"

uint QuestCategoryData::getId() const
{
  return m_id;
}

uint QuestCategoryData::getNameId() const
{
  return m_nameId;
}

uint QuestCategoryData::getOrder() const
{
  return m_order;
}

QList<uint> QuestCategoryData::getQuestIds() const
{
  return m_questIds;
}

QString QuestCategoryData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void QuestCategoryData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "order")
        m_order = readUInt(field->getValue());
    
    else if(field->getName() == "questIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_questIds << readUInt(data);
    }
    
  }
}

