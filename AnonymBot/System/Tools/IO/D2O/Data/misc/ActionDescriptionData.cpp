#include "ActionDescriptionData.h"

uint ActionDescriptionData::getId() const
{
  return m_id;
}

uint ActionDescriptionData::getTypeId() const
{
  return m_typeId;
}

QString ActionDescriptionData::getName() const
{
  return m_name;
}

uint ActionDescriptionData::getDescriptionId() const
{
  return m_descriptionId;
}

bool ActionDescriptionData::getTrusted() const
{
  return m_trusted;
}

bool ActionDescriptionData::getNeedInteraction() const
{
  return m_needInteraction;
}

uint ActionDescriptionData::getMaxUsePerFrame() const
{
  return m_maxUsePerFrame;
}

uint ActionDescriptionData::getMinimalUseInterval() const
{
  return m_minimalUseInterval;
}

bool ActionDescriptionData::getNeedConfirmation() const
{
  return m_needConfirmation;
}

QString ActionDescriptionData::getDescription() const
{
  return m_I18n->getText(m_descriptionId);
}

void ActionDescriptionData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "typeId")
        m_typeId = readUInt(field->getValue());
    
    else if(field->getName() == "name")
        m_name = readUTF(field->getValue());
    
    else if(field->getName() == "descriptionId")
        m_descriptionId = readUInt(field->getValue());
    
    else if(field->getName() == "trusted")
        m_trusted = readBool(field->getValue());
    
    else if(field->getName() == "needInteraction")
        m_needInteraction = readBool(field->getValue());
    
    else if(field->getName() == "maxUsePerFrame")
        m_maxUsePerFrame = readUInt(field->getValue());
    
    else if(field->getName() == "minimalUseInterval")
        m_minimalUseInterval = readUInt(field->getValue());
    
    else if(field->getName() == "needConfirmation")
        m_needConfirmation = readBool(field->getValue());
    
  }
}

