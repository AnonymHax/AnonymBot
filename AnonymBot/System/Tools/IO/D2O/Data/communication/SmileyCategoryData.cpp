#include "SmileyCategoryData.h"

int SmileyCategoryData::getId() const
{
  return m_id;
}

uint SmileyCategoryData::getOrder() const
{
  return m_order;
}

QString SmileyCategoryData::getGfxId() const
{
  return m_gfxId;
}

bool SmileyCategoryData::getIsFake() const
{
  return m_isFake;
}

void SmileyCategoryData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "order")
        m_order = readUInt(field->getValue());
    
    else if(field->getName() == "gfxId")
        m_gfxId = readUTF(field->getValue());
    
    else if(field->getName() == "isFake")
        m_isFake = readBool(field->getValue());
    
  }
}

