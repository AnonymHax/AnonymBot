#include "ServerCommunityData.h"

int ServerCommunityData::getId() const
{
  return m_id;
}

uint ServerCommunityData::getNameId() const
{
  return m_nameId;
}

QString ServerCommunityData::getShortId() const
{
  return m_shortId;
}

QList<QString> ServerCommunityData::getDefaultCountries() const
{
  return m_defaultCountries;
}

QString ServerCommunityData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void ServerCommunityData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "shortId")
        m_shortId = readUTF(field->getValue());
    
    else if(field->getName() == "defaultCountries")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_defaultCountries << readUTF(data);
    }
    
  }
}

