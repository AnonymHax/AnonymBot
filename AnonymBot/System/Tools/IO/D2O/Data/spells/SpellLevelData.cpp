#include "SpellLevelData.h"

uint SpellLevelData::getId() const
{
  return m_id;
}

uint SpellLevelData::getSpellId() const
{
  return m_spellId;
}

uint SpellLevelData::getGrade() const
{
  return m_grade;
}

uint SpellLevelData::getSpellBreed() const
{
  return m_spellBreed;
}

uint SpellLevelData::getApCost() const
{
  return m_apCost;
}

uint SpellLevelData::getMinRange() const
{
  return m_minRange;
}

uint SpellLevelData::getRange() const
{
  return m_range;
}

bool SpellLevelData::getCastInLine() const
{
  return m_castInLine;
}

bool SpellLevelData::getCastInDiagonal() const
{
  return m_castInDiagonal;
}

bool SpellLevelData::getCastTestLos() const
{
  return m_castTestLos;
}

uint SpellLevelData::getCriticalHitProbability() const
{
  return m_criticalHitProbability;
}

bool SpellLevelData::getNeedFreeCell() const
{
  return m_needFreeCell;
}

bool SpellLevelData::getNeedTakenCell() const
{
  return m_needTakenCell;
}

bool SpellLevelData::getNeedFreeTrapCell() const
{
  return m_needFreeTrapCell;
}

bool SpellLevelData::getRangeCanBeBoosted() const
{
  return m_rangeCanBeBoosted;
}

int SpellLevelData::getMaxStack() const
{
  return m_maxStack;
}

uint SpellLevelData::getMaxCastPerTurn() const
{
  return m_maxCastPerTurn;
}

uint SpellLevelData::getMaxCastPerTarget() const
{
  return m_maxCastPerTarget;
}

uint SpellLevelData::getMinCastInterval() const
{
  return m_minCastInterval;
}

uint SpellLevelData::getInitialCooldown() const
{
  return m_initialCooldown;
}

int SpellLevelData::getGlobalCooldown() const
{
  return m_globalCooldown;
}

uint SpellLevelData::getMinPlayerLevel() const
{
  return m_minPlayerLevel;
}

bool SpellLevelData::getHideEffects() const
{
  return m_hideEffects;
}

bool SpellLevelData::getHidden() const
{
  return m_hidden;
}

bool SpellLevelData::getPlayAnimation() const
{
  return m_playAnimation;
}

QList<int> SpellLevelData::getStatesRequired() const
{
  return m_statesRequired;
}

QList<int> SpellLevelData::getStatesForbidden() const
{
  return m_statesForbidden;
}

QList<EffectInstanceDiceData> SpellLevelData::getEffects() const
{
  return m_effects;
}

QList<EffectInstanceDiceData> SpellLevelData::getCriticalEffect() const
{
  return m_criticalEffect;
}

void SpellLevelData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readUInt(field->getValue());
    
    else if(field->getName() == "spellId")
        m_spellId = readUInt(field->getValue());
    
    else if(field->getName() == "grade")
        m_grade = readUInt(field->getValue());
    
    else if(field->getName() == "spellBreed")
        m_spellBreed = readUInt(field->getValue());
    
    else if(field->getName() == "apCost")
        m_apCost = readUInt(field->getValue());
    
    else if(field->getName() == "minRange")
        m_minRange = readUInt(field->getValue());
    
    else if(field->getName() == "range")
        m_range = readUInt(field->getValue());
    
    else if(field->getName() == "castInLine")
        m_castInLine = readBool(field->getValue());
    
    else if(field->getName() == "castInDiagonal")
        m_castInDiagonal = readBool(field->getValue());
    
    else if(field->getName() == "castTestLos")
        m_castTestLos = readBool(field->getValue());
    
    else if(field->getName() == "criticalHitProbability")
        m_criticalHitProbability = readUInt(field->getValue());
    
    else if(field->getName() == "needFreeCell")
        m_needFreeCell = readBool(field->getValue());
    
    else if(field->getName() == "needTakenCell")
        m_needTakenCell = readBool(field->getValue());
    
    else if(field->getName() == "needFreeTrapCell")
        m_needFreeTrapCell = readBool(field->getValue());
    
    else if(field->getName() == "rangeCanBeBoosted")
        m_rangeCanBeBoosted = readBool(field->getValue());
    
    else if(field->getName() == "maxStack")
        m_maxStack = readInt(field->getValue());
    
    else if(field->getName() == "maxCastPerTurn")
        m_maxCastPerTurn = readUInt(field->getValue());
    
    else if(field->getName() == "maxCastPerTarget")
        m_maxCastPerTarget = readUInt(field->getValue());
    
    else if(field->getName() == "minCastInterval")
        m_minCastInterval = readUInt(field->getValue());
    
    else if(field->getName() == "initialCooldown")
        m_initialCooldown = readUInt(field->getValue());
    
    else if(field->getName() == "globalCooldown")
        m_globalCooldown = readInt(field->getValue());
    
    else if(field->getName() == "minPlayerLevel")
        m_minPlayerLevel = readUInt(field->getValue());
    
    else if(field->getName() == "hideEffects")
        m_hideEffects = readBool(field->getValue());
    
    else if(field->getName() == "hidden")
        m_hidden = readBool(field->getValue());
    
    else if(field->getName() == "playAnimation")
        m_playAnimation = readBool(field->getValue());
    
    else if(field->getName() == "statesRequired")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_statesRequired << readInt(data);
    }
    
    else if(field->getName() == "statesForbidden")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_statesForbidden << readInt(data);
    }
    
    else if(field->getName() == "effects")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_effects << *qSharedPointerCast<EffectInstanceDiceData>(readObject(data, field)).data();
    }
    
    else if(field->getName() == "criticalEffect")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_criticalEffect << *qSharedPointerCast<EffectInstanceDiceData>(readObject(data, field)).data();
    }
    
  }
}

