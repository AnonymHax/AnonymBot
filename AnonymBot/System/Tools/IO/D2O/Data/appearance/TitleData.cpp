#include "TitleData.h"

int TitleData::getId() const
{
  return m_id;
}

uint TitleData::getNameMaleId() const
{
  return m_nameMaleId;
}

uint TitleData::getNameFemaleId() const
{
  return m_nameFemaleId;
}

bool TitleData::getVisible() const
{
  return m_visible;
}

int TitleData::getCategoryId() const
{
  return m_categoryId;
}

QString TitleData::getNameMale() const
{
  return m_I18n->getText(m_nameMaleId);
}

QString TitleData::getNameFemale() const
{
  return m_I18n->getText(m_nameFemaleId);
}

void TitleData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameMaleId")
        m_nameMaleId = readUInt(field->getValue());
    
    else if(field->getName() == "nameFemaleId")
        m_nameFemaleId = readUInt(field->getValue());
    
    else if(field->getName() == "visible")
        m_visible = readBool(field->getValue());
    
    else if(field->getName() == "categoryId")
        m_categoryId = readInt(field->getValue());
    
  }
}

