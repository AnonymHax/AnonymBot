#include "AlignmentRankData.h"

int AlignmentRankData::getId() const
{
  return m_id;
}

uint AlignmentRankData::getOrderId() const
{
  return m_orderId;
}

uint AlignmentRankData::getNameId() const
{
  return m_nameId;
}

uint AlignmentRankData::getDescriptionId() const
{
  return m_descriptionId;
}

int AlignmentRankData::getMinimumAlignment() const
{
  return m_minimumAlignment;
}

int AlignmentRankData::getObjectsStolen() const
{
  return m_objectsStolen;
}

QList<int> AlignmentRankData::getGifts() const
{
  return m_gifts;
}

QString AlignmentRankData::getName() const
{
  return m_I18n->getText(m_nameId);
}

QString AlignmentRankData::getDescription() const
{
  return m_I18n->getText(m_descriptionId);
}

void AlignmentRankData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "orderId")
        m_orderId = readUInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "descriptionId")
        m_descriptionId = readUInt(field->getValue());
    
    else if(field->getName() == "minimumAlignment")
        m_minimumAlignment = readInt(field->getValue());
    
    else if(field->getName() == "objectsStolen")
        m_objectsStolen = readInt(field->getValue());
    
    else if(field->getName() == "gifts")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_gifts << readInt(data);
    }
    
  }
}

