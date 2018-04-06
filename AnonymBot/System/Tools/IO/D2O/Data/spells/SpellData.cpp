#include "SpellData.h"

int SpellData::getId() const
{
  return m_id;
}

uint SpellData::getNameId() const
{
  return m_nameId;
}

uint SpellData::getDescriptionId() const
{
  return m_descriptionId;
}

uint SpellData::getTypeId() const
{
  return m_typeId;
}

uint SpellData::getOrder() const
{
  return m_order;
}

QString SpellData::getScriptParams() const
{
  return m_scriptParams;
}

QString SpellData::getScriptParamsCritical() const
{
  return m_scriptParamsCritical;
}

int SpellData::getScriptId() const
{
  return m_scriptId;
}

int SpellData::getScriptIdCritical() const
{
  return m_scriptIdCritical;
}

uint SpellData::getIconId() const
{
  return m_iconId;
}

QList<uint> SpellData::getSpellLevels() const
{
  return m_spellLevels;
}

QList<int> SpellData::getVariants() const
{
  return m_variants;
}

bool SpellData::getUseParamCache() const
{
  return m_useParamCache;
}

uint SpellData::getObtentionLevel() const
{
  return m_obtentionLevel;
}

bool SpellData::getUseSpellLevelScaling() const
{
  return m_useSpellLevelScaling;
}

QString SpellData::getName() const
{
  return m_I18n->getText(m_nameId);
}

QString SpellData::getDescription() const
{
  return m_I18n->getText(m_descriptionId);
}

void SpellData::loadData(const QList<Field*> &fields, I18nFile *I18n)
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
    
    else if(field->getName() == "typeId")
        m_typeId = readUInt(field->getValue());
    
    else if(field->getName() == "order")
        m_order = readUInt(field->getValue());
    
    else if(field->getName() == "scriptParams")
        m_scriptParams = readUTF(field->getValue());
    
    else if(field->getName() == "scriptParamsCritical")
        m_scriptParamsCritical = readUTF(field->getValue());
    
    else if(field->getName() == "scriptId")
        m_scriptId = readInt(field->getValue());
    
    else if(field->getName() == "scriptIdCritical")
        m_scriptIdCritical = readInt(field->getValue());
    
    else if(field->getName() == "iconId")
        m_iconId = readUInt(field->getValue());
    
    else if(field->getName() == "spellLevels")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_spellLevels << readUInt(data);
    }
    
    else if(field->getName() == "variants")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_variants << readInt(data);
    }
    
    else if(field->getName() == "useParamCache")
        m_useParamCache = readBool(field->getValue());
    
    else if(field->getName() == "obtentionLevel")
        m_obtentionLevel = readUInt(field->getValue());
    
    else if(field->getName() == "useSpellLevelScaling")
        m_useSpellLevelScaling = readBool(field->getValue());
    
  }
}

