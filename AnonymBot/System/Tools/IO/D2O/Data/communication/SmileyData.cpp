#include "SmileyData.h"

uint SmileyData::getId() const
{
  return m_id;
}

uint SmileyData::getOrder() const
{
  return m_order;
}

QString SmileyData::getGfxId() const
{
  return m_gfxId;
}

bool SmileyData::getForPlayers() const
{
  return m_forPlayers;
}

QList<QString> SmileyData::getTriggers() const
{
  return m_triggers;
}

uint SmileyData::getReferenceId() const
{
  return m_referenceId;
}

uint SmileyData::getCategoryId() const
{
  return m_categoryId;
}

void SmileyData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "order")
        m_order = readUInt(field->getValue());
    
    else if(field->getName() == "gfxId")
        m_gfxId = readUTF(field->getValue());
    
    else if(field->getName() == "forPlayers")
        m_forPlayers = readBool(field->getValue());
    
    else if(field->getName() == "triggers")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_triggers << readUTF(data);
    }
    
    else if(field->getName() == "referenceId")
        m_referenceId = readUInt(field->getValue());
    
    else if(field->getName() == "categoryId")
        m_categoryId = readUInt(field->getValue());
    
  }
}

