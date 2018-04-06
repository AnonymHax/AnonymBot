#include "ExternalNotificationData.h"

int ExternalNotificationData::getId() const
{
  return m_id;
}

int ExternalNotificationData::getCategoryId() const
{
  return m_categoryId;
}

int ExternalNotificationData::getIconId() const
{
  return m_iconId;
}

int ExternalNotificationData::getColorId() const
{
  return m_colorId;
}

uint ExternalNotificationData::getDescriptionId() const
{
  return m_descriptionId;
}

bool ExternalNotificationData::getDefaultEnable() const
{
  return m_defaultEnable;
}

bool ExternalNotificationData::getDefaultSound() const
{
  return m_defaultSound;
}

bool ExternalNotificationData::getDefaultNotify() const
{
  return m_defaultNotify;
}

bool ExternalNotificationData::getDefaultMultiAccount() const
{
  return m_defaultMultiAccount;
}

QString ExternalNotificationData::getName() const
{
  return m_name;
}

uint ExternalNotificationData::getMessageId() const
{
  return m_messageId;
}

QString ExternalNotificationData::getDescription() const
{
  return m_I18n->getText(m_descriptionId);
}

QString ExternalNotificationData::getMessage() const
{
  return m_I18n->getText(m_messageId);
}

void ExternalNotificationData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "categoryId")
        m_categoryId = readInt(field->getValue());
    
    else if(field->getName() == "iconId")
        m_iconId = readInt(field->getValue());
    
    else if(field->getName() == "colorId")
        m_colorId = readInt(field->getValue());
    
    else if(field->getName() == "descriptionId")
        m_descriptionId = readUInt(field->getValue());
    
    else if(field->getName() == "defaultEnable")
        m_defaultEnable = readBool(field->getValue());
    
    else if(field->getName() == "defaultSound")
        m_defaultSound = readBool(field->getValue());
    
    else if(field->getName() == "defaultNotify")
        m_defaultNotify = readBool(field->getValue());
    
    else if(field->getName() == "defaultMultiAccount")
        m_defaultMultiAccount = readBool(field->getValue());
    
    else if(field->getName() == "name")
        m_name = readUTF(field->getValue());
    
    else if(field->getName() == "messageId")
        m_messageId = readUInt(field->getValue());
    
  }
}

