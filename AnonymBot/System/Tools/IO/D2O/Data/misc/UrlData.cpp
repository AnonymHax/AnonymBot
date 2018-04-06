#include "UrlData.h"

int UrlData::getId() const
{
  return m_id;
}

int UrlData::getBrowserId() const
{
  return m_browserId;
}

QString UrlData::getUrl() const
{
  return m_url;
}

QString UrlData::getParam() const
{
  return m_param;
}

QString UrlData::getMethod() const
{
  return m_method;
}

void UrlData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "browserId")
        m_browserId = readInt(field->getValue());
    
    else if(field->getName() == "url")
        m_url = readUTF(field->getValue());
    
    else if(field->getName() == "param")
        m_param = readUTF(field->getValue());
    
    else if(field->getName() == "method")
        m_method = readUTF(field->getValue());
    
  }
}

