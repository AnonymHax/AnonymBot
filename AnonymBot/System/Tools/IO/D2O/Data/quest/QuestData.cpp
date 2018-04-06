#include "QuestData.h"

uint QuestData::getId() const
{
  return m_id;
}

uint QuestData::getNameId() const
{
  return m_nameId;
}

QList<uint> QuestData::getStepIds() const
{
  return m_stepIds;
}

uint QuestData::getCategoryId() const
{
  return m_categoryId;
}

uint QuestData::getRepeatType() const
{
  return m_repeatType;
}

uint QuestData::getRepeatLimit() const
{
  return m_repeatLimit;
}

bool QuestData::getIsDungeonQuest() const
{
  return m_isDungeonQuest;
}

uint QuestData::getLevelMin() const
{
  return m_levelMin;
}

uint QuestData::getLevelMax() const
{
  return m_levelMax;
}

bool QuestData::getIsPartyQuest() const
{
  return m_isPartyQuest;
}

QString QuestData::getStartCriterion() const
{
  return m_startCriterion;
}

QString QuestData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void QuestData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "stepIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_stepIds << readUInt(data);
    }
    
    else if(field->getName() == "categoryId")
        m_categoryId = readUInt(field->getValue());
    
    else if(field->getName() == "repeatType")
        m_repeatType = readUInt(field->getValue());
    
    else if(field->getName() == "repeatLimit")
        m_repeatLimit = readUInt(field->getValue());
    
    else if(field->getName() == "isDungeonQuest")
        m_isDungeonQuest = readBool(field->getValue());
    
    else if(field->getName() == "levelMin")
        m_levelMin = readUInt(field->getValue());
    
    else if(field->getName() == "levelMax")
        m_levelMax = readUInt(field->getValue());
    
    else if(field->getName() == "isPartyQuest")
        m_isPartyQuest = readBool(field->getValue());
    
    else if(field->getName() == "startCriterion")
        m_startCriterion = readUTF(field->getValue());
    
  }
}

