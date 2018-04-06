#include "MonsterData.h"

int MonsterData::getId() const
{
  return m_id;
}

uint MonsterData::getNameId() const
{
  return m_nameId;
}

uint MonsterData::getGfxId() const
{
  return m_gfxId;
}

int MonsterData::getRace() const
{
  return m_race;
}

QList<MonsterGradeData> MonsterData::getGrades() const
{
  return m_grades;
}

QString MonsterData::getLook() const
{
  return m_look;
}

bool MonsterData::getUseSummonSlot() const
{
  return m_useSummonSlot;
}

bool MonsterData::getUseBombSlot() const
{
  return m_useBombSlot;
}

bool MonsterData::getCanPlay() const
{
  return m_canPlay;
}

bool MonsterData::getCanTackle() const
{
  return m_canTackle;
}

bool MonsterData::getIsBoss() const
{
  return m_isBoss;
}

QList<MonsterDropData> MonsterData::getDrops() const
{
  return m_drops;
}

QList<uint> MonsterData::getSubareas() const
{
  return m_subareas;
}

QList<uint> MonsterData::getSpells() const
{
  return m_spells;
}

int MonsterData::getFavoriteSubareaId() const
{
  return m_favoriteSubareaId;
}

bool MonsterData::getIsMiniBoss() const
{
  return m_isMiniBoss;
}

bool MonsterData::getIsQuestMonster() const
{
  return m_isQuestMonster;
}

uint MonsterData::getCorrespondingMiniBossId() const
{
  return m_correspondingMiniBossId;
}

double MonsterData::getSpeedAdjust() const
{
  return m_speedAdjust;
}

int MonsterData::getCreatureBoneId() const
{
  return m_creatureBoneId;
}

bool MonsterData::getCanBePushed() const
{
  return m_canBePushed;
}

bool MonsterData::getFastAnimsFun() const
{
  return m_fastAnimsFun;
}

bool MonsterData::getCanSwitchPos() const
{
  return m_canSwitchPos;
}

QList<uint> MonsterData::getIncompatibleIdols() const
{
  return m_incompatibleIdols;
}

bool MonsterData::getAllIdolsDisabled() const
{
  return m_allIdolsDisabled;
}

bool MonsterData::getDareAvailable() const
{
  return m_dareAvailable;
}

QList<uint> MonsterData::getIncompatibleChallenges() const
{
  return m_incompatibleChallenges;
}

QString MonsterData::getName() const
{
  return m_I18n->getText(m_nameId);
}

void MonsterData::loadData(const QList<Field*> &fields, I18nFile *I18n)
{
  m_I18n = I18n;
  
  foreach (Field *field, fields)
  {
    if(field->getName() == "id")
        m_id = readInt(field->getValue());
    
    else if(field->getName() == "nameId")
        m_nameId = readUInt(field->getValue());
    
    else if(field->getName() == "gfxId")
        m_gfxId = readUInt(field->getValue());
    
    else if(field->getName() == "race")
        m_race = readInt(field->getValue());
    
    else if(field->getName() == "grades")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_grades << *qSharedPointerCast<MonsterGradeData>(readObject(data, field)).data();
    }
    
    else if(field->getName() == "look")
        m_look = readUTF(field->getValue());
    
    else if(field->getName() == "useSummonSlot")
        m_useSummonSlot = readBool(field->getValue());
    
    else if(field->getName() == "useBombSlot")
        m_useBombSlot = readBool(field->getValue());
    
    else if(field->getName() == "canPlay")
        m_canPlay = readBool(field->getValue());
    
    else if(field->getName() == "canTackle")
        m_canTackle = readBool(field->getValue());
    
    else if(field->getName() == "isBoss")
        m_isBoss = readBool(field->getValue());
    
    else if(field->getName() == "drops")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_drops << *qSharedPointerCast<MonsterDropData>(readObject(data, field)).data();
    }
    
    else if(field->getName() == "subareas")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_subareas << readUInt(data);
    }
    
    else if(field->getName() == "spells")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_spells << readUInt(data);
    }
    
    else if(field->getName() == "favoriteSubareaId")
        m_favoriteSubareaId = readInt(field->getValue());
    
    else if(field->getName() == "isMiniBoss")
        m_isMiniBoss = readBool(field->getValue());
    
    else if(field->getName() == "isQuestMonster")
        m_isQuestMonster = readBool(field->getValue());
    
    else if(field->getName() == "correspondingMiniBossId")
        m_correspondingMiniBossId = readUInt(field->getValue());
    
    else if(field->getName() == "speedAdjust")
        m_speedAdjust = readDouble(field->getValue());
    
    else if(field->getName() == "creatureBoneId")
        m_creatureBoneId = readInt(field->getValue());
    
    else if(field->getName() == "canBePushed")
        m_canBePushed = readBool(field->getValue());
    
    else if(field->getName() == "fastAnimsFun")
        m_fastAnimsFun = readBool(field->getValue());
    
    else if(field->getName() == "canSwitchPos")
        m_canSwitchPos = readBool(field->getValue());
    
    else if(field->getName() == "incompatibleIdols")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_incompatibleIdols << readUInt(data);
    }
    
    else if(field->getName() == "allIdolsDisabled")
        m_allIdolsDisabled = readBool(field->getValue());
    
    else if(field->getName() == "dareAvailable")
        m_dareAvailable = readBool(field->getValue());
    
    else if(field->getName() == "incompatibleChallenges")
    {
      foreach(const QByteArray &data, readVector(field->getValue()))
          m_incompatibleChallenges << readUInt(data);
    }
    
  }
}

