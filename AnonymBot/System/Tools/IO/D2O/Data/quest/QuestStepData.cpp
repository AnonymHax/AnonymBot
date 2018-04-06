#include "QuestStepData.h"

uint QuestStepData::getId() const
{
  return m_id;
}

uint QuestStepData::getQuestId() const
{
  return m_questId;
}

uint QuestStepData::getNameId() const
{
  return m_nameId;
}

uint QuestStepData::getDescriptionId() const
{
  return m_descriptionId;
}

int QuestStepData::getDialogId() const
{
  return m_dialogId;
}

uint QuestStepData::getOptimalLevel() const
{
  return m_optimalLevel;
}

double QuestStepData::getDuration() const
{
  return m_duration;
}

bool QuestStepData::getKamasScaleWithPlayerLevel() const
{
  return m_kamasScaleWithPlayerLevel;
}

double QuestStepData::getKamasRatio() const
{
  return m_kamasRatio;
}

double QuestStepData::getXpRatio() const
{
  return m_xpRatio;
}

QList<uint> QuestStepData::getObjectiveIds() const
{
  return m_objectiveIds;
}

QList<uint> QuestStepData::getRewardsIds() const
{
  return m_rewardsIds;
}

QString QuestStepData::getName() const
{
  return m_I18n->getText(m_nameId);
}

QString QuestStepData::getDescription() const
{
  return m_I18n->getText(m_descriptionId);
}

QString QuestStepData::getDialog() const
{
  return m_I18n->getText(m_dialogId);
}

void QuestStepData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "questId")
        m_questId = readUInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "descriptionId")
        m_descriptionId = readUInt(field->getValue());
    
    else if(field->getName() == "dialogId")
        m_dialogId = readInt(field->getValue());
    
    else if(field->getName() == "optimalLevel")
        m_optimalLevel = readUInt(field->getValue());
    
    else if(field->getName() == "duration")
        m_duration = readDouble(field->getValue());
    
    else if(field->getName() == "kamasScaleWithPlayerLevel")
        m_kamasScaleWithPlayerLevel = readBool(field->getValue());
    
    else if(field->getName() == "kamasRatio")
        m_kamasRatio = readDouble(field->getValue());
    
    else if(field->getName() == "xpRatio")
        m_xpRatio = readDouble(field->getValue());
    
    else if(field->getName() == "objectiveIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_objectiveIds << readUInt(data);
    }
    
    else if(field->getName() == "rewardsIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_rewardsIds << readUInt(data);
    }
    
  }
}

