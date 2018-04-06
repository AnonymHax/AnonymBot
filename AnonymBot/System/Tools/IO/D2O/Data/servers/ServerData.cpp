#include "ServerData.h"

int ServerData::getId() const
{
  return m_id;
}

uint ServerData::getNameId() const
{
  return m_nameId;
}

uint ServerData::getCommentId() const
{
  return m_commentId;
}

double ServerData::getOpeningDate() const
{
  return m_openingDate;
}

QString ServerData::getLanguage() const
{
  return m_language;
}

int ServerData::getPopulationId() const
{
  return m_populationId;
}

uint ServerData::getGameTypeId() const
{
  return m_gameTypeId;
}

int ServerData::getCommunityId() const
{
  return m_communityId;
}

QList<QString> ServerData::getRestrictedToLanguages() const
{
  return m_restrictedToLanguages;
}

QString ServerData::getName() const
{
  return m_I18n->getText(m_nameId);
}

QString ServerData::getComment() const
{
  return m_I18n->getText(m_commentId);
}

void ServerData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "commentId")
        m_commentId = readUInt(field->getValue());
    
    else if(field->getName() == "openingDate")
        m_openingDate = readDouble(field->getValue());
    
    else if(field->getName() == "language")
        m_language = readUTF(field->getValue());
    
    else if(field->getName() == "populationId")
        m_populationId = readInt(field->getValue());
    
    else if(field->getName() == "gameTypeId")
        m_gameTypeId = readUInt(field->getValue());
    
    else if(field->getName() == "communityId")
        m_communityId = readInt(field->getValue());
    
    else if(field->getName() == "restrictedToLanguages")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_restrictedToLanguages << readUTF(data);
    }
    
  }
}

