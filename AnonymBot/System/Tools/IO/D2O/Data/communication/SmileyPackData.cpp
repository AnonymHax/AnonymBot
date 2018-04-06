#include "SmileyPackData.h"

uint SmileyPackData::getId() const
{
  return m_id;
}

uint SmileyPackData::getNameId() const
{
  return m_nameId;
}

uint SmileyPackData::getOrder() const
{
  return m_order;
}

QList<uint> SmileyPackData::getSmileys() const
{
  return m_smileys;
}

QString SmileyPackData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void SmileyPackData::loadData(const QList<Field*> &fields, I18nFile *I18n)
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
    
    else if(field->getName() == "smileys")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_smileys << readUInt(data);
    }
    
  }
}

