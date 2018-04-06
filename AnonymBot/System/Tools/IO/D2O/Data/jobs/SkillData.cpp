#include "SkillData.h"

int SkillData::getId() const
{
  return m_id;
}

uint SkillData::getNameId() const
{
  return m_nameId;
}

int SkillData::getParentJobId() const
{
  return m_parentJobId;
}

bool SkillData::getIsForgemagus() const
{
  return m_isForgemagus;
}

QList<int> SkillData::getModifiableItemTypeIds() const
{
  return m_modifiableItemTypeIds;
}

int SkillData::getGatheredRessourceItem() const
{
  return m_gatheredRessourceItem;
}

QList<int> SkillData::getCraftableItemIds() const
{
  return m_craftableItemIds;
}

int SkillData::getInteractiveId() const
{
  return m_interactiveId;
}

QString SkillData::getUseAnimation() const
{
  return m_useAnimation;
}

int SkillData::getCursor() const
{
  return m_cursor;
}

int SkillData::getElementActionId() const
{
  return m_elementActionId;
}

bool SkillData::getAvailableInHouse() const
{
  return m_availableInHouse;
}

uint SkillData::getLevelMin() const
{
  return m_levelMin;
}

bool SkillData::getClientDisplay() const
{
  return m_clientDisplay;
}

QString SkillData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void SkillData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "parentJobId")
        m_parentJobId = readInt(field->getValue());
    
    else if(field->getName() == "isForgemagus")
        m_isForgemagus = readBool(field->getValue());
    
    else if(field->getName() == "modifiableItemTypeIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_modifiableItemTypeIds << readInt(data);
    }
    
    else if(field->getName() == "gatheredRessourceItem")
        m_gatheredRessourceItem = readInt(field->getValue());
    
    else if(field->getName() == "craftableItemIds")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_craftableItemIds << readInt(data);
    }
    
    else if(field->getName() == "interactiveId")
        m_interactiveId = readInt(field->getValue());
    
    else if(field->getName() == "useAnimation")
        m_useAnimation = readUTF(field->getValue());
    
    else if(field->getName() == "cursor")
        m_cursor = readInt(field->getValue());
    
    else if(field->getName() == "elementActionId")
        m_elementActionId = readInt(field->getValue());
    
    else if(field->getName() == "availableInHouse")
        m_availableInHouse = readBool(field->getValue());
    
    else if(field->getName() == "levelMin")
        m_levelMin = readUInt(field->getValue());
    
    else if(field->getName() == "clientDisplay")
        m_clientDisplay = readBool(field->getValue());
    
  }
}

