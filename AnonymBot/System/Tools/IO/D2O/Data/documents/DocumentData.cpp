#include "DocumentData.h"

int DocumentData::getId() const
{
  return m_id;
}

uint DocumentData::getTypeId() const
{
  return m_typeId;
}

bool DocumentData::getShowTitle() const
{
  return m_showTitle;
}

bool DocumentData::getShowBackgroundImage() const
{
  return m_showBackgroundImage;
}

uint DocumentData::getTitleId() const
{
  return m_titleId;
}

uint DocumentData::getAuthorId() const
{
  return m_authorId;
}

uint DocumentData::getSubTitleId() const
{
  return m_subTitleId;
}

uint DocumentData::getContentId() const
{
  return m_contentId;
}

QString DocumentData::getContentCSS() const
{
  return m_contentCSS;
}

QString DocumentData::getClientProperties() const
{
  return m_clientProperties;
}

QString DocumentData::getTitle() const
{
  return m_I18n->getText(m_titleId);
}

QString DocumentData::getAuthor() const
{
  return m_I18n->getText(m_authorId);
}

QString DocumentData::getSubTitle() const
{
  return m_I18n->getText(m_subTitleId);
}

QString DocumentData::getContent() const
{
  return m_I18n->getText(m_contentId);
}

void DocumentData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "typeId")
        m_typeId = readUInt(field->getValue());
    
    else if(field->getName() == "showTitle")
        m_showTitle = readBool(field->getValue());
    
    else if(field->getName() == "showBackgroundImage")
        m_showBackgroundImage = readBool(field->getValue());
    
    else if(field->getName() == "titleId")
        m_titleId = readUInt(field->getValue());
    
    else if(field->getName() == "authorId")
        m_authorId = readUInt(field->getValue());
    
    else if(field->getName() == "subTitleId")
        m_subTitleId = readUInt(field->getValue());
    
    else if(field->getName() == "contentId")
        m_contentId = readUInt(field->getValue());
    
    else if(field->getName() == "contentCSS")
        m_contentCSS = readUTF(field->getValue());
    
    else if(field->getName() == "clientProperties")
        m_clientProperties = readUTF(field->getValue());
    
  }
}

