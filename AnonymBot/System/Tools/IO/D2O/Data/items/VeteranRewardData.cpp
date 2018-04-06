#include "VeteranRewardData.h"

int VeteranRewardData::getId() const
{
  return m_id;
}

uint VeteranRewardData::getRequiredSubDays() const
{
  return m_requiredSubDays;
}

uint VeteranRewardData::getItemGID() const
{
  return m_itemGID;
}

uint VeteranRewardData::getItemQuantity() const
{
  return m_itemQuantity;
}

void VeteranRewardData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "requiredSubDays")
        m_requiredSubDays = readUInt(field->getValue());
    
    else if(field->getName() == "itemGID")
        m_itemGID = readUInt(field->getValue());
    
    else if(field->getName() == "itemQuantity")
        m_itemQuantity = readUInt(field->getValue());
    
  }
}

