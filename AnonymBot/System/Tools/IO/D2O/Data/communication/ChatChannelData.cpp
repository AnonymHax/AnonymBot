#include "ChatChannelData.h"

uint ChatChannelData::getId() const
{
  return m_id;
}

uint ChatChannelData::getNameId() const
{
  return m_nameId;
}

uint ChatChannelData::getDescriptionId() const
{
  return m_descriptionId;
}

QString ChatChannelData::getShortcut() const
{
  return m_shortcut;
}

QString ChatChannelData::getShortcutKey() const
{
  return m_shortcutKey;
}

bool ChatChannelData::getIsPrivate() const
{
  return m_isPrivate;
}

bool ChatChannelData::getAllowObjects() const
{
  return m_allowObjects;
}

QString ChatChannelData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void ChatChannelData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "descriptionId")
        m_descriptionId = readUInt(field->getValue());
    
    else if(field->getName() == "shortcut")
        m_shortcut = readUTF(field->getValue());
    
    else if(field->getName() == "shortcutKey")
        m_shortcutKey = readUTF(field->getValue());
    
    else if(field->getName() == "isPrivate")
        m_isPrivate = readBool(field->getValue());
    
    else if(field->getName() == "allowObjects")
        m_allowObjects = readBool(field->getValue());
    
  }
}

