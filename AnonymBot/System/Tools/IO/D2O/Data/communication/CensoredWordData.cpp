#include "CensoredWordData.h"

uint CensoredWordData::getId() const
{
  return m_id;
}

uint CensoredWordData::getListId() const
{
  return m_listId;
}

QString CensoredWordData::getLanguage() const
{
  return m_language;
}

QString CensoredWordData::getWord() const
{
  return m_word;
}

bool CensoredWordData::getDeepLooking() const
{
  return m_deepLooking;
}

void CensoredWordData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "listId")
        m_listId = readUInt(field->getValue());
    
    else if(field->getName() == "language")
        m_language = readUTF(field->getValue());
    
    else if(field->getName() == "word")
        m_word = readUTF(field->getValue());
    
    else if(field->getName() == "deepLooking")
        m_deepLooking = readBool(field->getValue());
    
  }
}

