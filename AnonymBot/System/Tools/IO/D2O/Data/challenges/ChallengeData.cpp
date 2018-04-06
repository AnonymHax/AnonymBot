#include "ChallengeData.h"

int ChallengeData::getId() const
{
  return m_id;
}

uint ChallengeData::getNameId() const
{
  return m_nameId;
}

uint ChallengeData::getDescriptionId() const
{
  return m_descriptionId;
}

bool ChallengeData::getDareAvailable() const
{
  return m_dareAvailable;
}

QList<uint> ChallengeData::getIncompatibleChallenges() const
{
  return m_incompatibleChallenges;
}

QString ChallengeData::getName() const
{
  return m_I18n->getText(m_nameId);
}

QString ChallengeData::getDescription() const
{
  return m_I18n->getText(m_descriptionId);
}

void ChallengeData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "descriptionId")
        m_descriptionId = readUInt(field->getValue());
    
    else if(field->getName() == "dareAvailable")
        m_dareAvailable = readBool(field->getValue());
    
    else if(field->getName() == "incompatibleChallenges")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_incompatibleChallenges << readUInt(data);
    }
    
  }
}

