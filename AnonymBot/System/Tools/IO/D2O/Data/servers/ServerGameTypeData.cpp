#include "ServerGameTypeData.h"

int ServerGameTypeData::getId() const
{
  return m_id;
}

uint ServerGameTypeData::getNameId() const
{
  return m_nameId;
}

QString ServerGameTypeData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void ServerGameTypeData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
  }
}

