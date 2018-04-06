#include "CompanionData.h"

int CompanionData::getId() const
{
  return m_id;
}

uint CompanionData::getNameId() const
{
  return m_nameId;
}

QString CompanionData::getLook() const
{
  return m_look;
}

bool CompanionData::getWebDisplay() const
{
  return m_webDisplay;
}

uint CompanionData::getDescriptionId() const
{
  return m_descriptionId;
}

uint CompanionData::getStartingSpellLevelId() const
{
  return m_startingSpellLevelId;
}

uint CompanionData::getAssetId() const
{
  return m_assetId;
}

QList<uint> CompanionData::getCharacteristics() const
{
  return m_characteristics;
}

QList<uint> CompanionData::getSpells() const
{
  return m_spells;
}

int CompanionData::getCreatureBoneId() const
{
  return m_creatureBoneId;
}

QString CompanionData::getName() const
{
  return m_I18n->getText(m_nameId);
}

QString CompanionData::getDescription() const
{
  return m_I18n->getText(m_descriptionId);
}

void CompanionData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "look")
        m_look = readUTF(field->getValue());
    
    else if(field->getName() == "webDisplay")
        m_webDisplay = readBool(field->getValue());
    
    else if(field->getName() == "descriptionId")
        m_descriptionId = readUInt(field->getValue());
    
    else if(field->getName() == "startingSpellLevelId")
        m_startingSpellLevelId = readUInt(field->getValue());
    
    else if(field->getName() == "assetId")
        m_assetId = readUInt(field->getValue());
    
    else if(field->getName() == "characteristics")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_characteristics << readUInt(data);
    }
    
    else if(field->getName() == "spells")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_spells << readUInt(data);
    }
    
    else if(field->getName() == "creatureBoneId")
        m_creatureBoneId = readInt(field->getValue());
    
  }
}

