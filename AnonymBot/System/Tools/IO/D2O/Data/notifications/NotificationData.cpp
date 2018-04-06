#include "NotificationData.h"

int NotificationData::getId() const
{
  return m_id;
}

uint NotificationData::getTitleId() const
{
  return m_titleId;
}

uint NotificationData::getMessageId() const
{
  return m_messageId;
}

int NotificationData::getIconId() const
{
  return m_iconId;
}

int NotificationData::getTypeId() const
{
  return m_typeId;
}

QString NotificationData::getTrigger() const
{
  return m_trigger;
}

QString NotificationData::getTitle() const
{
  return m_I18n->getText(m_titleId);
}

QString NotificationData::getMessage() const
{
  return m_I18n->getText(m_messageId);
}

void NotificationData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "titleId")
        m_titleId = readUInt(field->getValue());
    
    else if(field->getName() == "messageId")
        m_messageId = readUInt(field->getValue());
    
    else if(field->getName() == "iconId")
        m_iconId = readInt(field->getValue());
    
    else if(field->getName() == "typeId")
        m_typeId = readInt(field->getValue());
    
    else if(field->getName() == "trigger")
        m_trigger = readUTF(field->getValue());
    
  }
}

