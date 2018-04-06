#include "ComicData.h"

int ComicData::getId() const
{
  return m_id;
}

QString ComicData::getRemoteId() const
{
  return m_remoteId;
}

void ComicData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "remoteId")
        m_remoteId = readUTF(field->getValue());
    
  }
}

