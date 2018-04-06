#include "GameFightResumeSlaveInfo.h"

void GameFightResumeSlaveInfo::serialize(Writer *param1)
{
  this->serializeAs_GameFightResumeSlaveInfo(param1);
}

void GameFightResumeSlaveInfo::serializeAs_GameFightResumeSlaveInfo(Writer *param1)
{
  if(this->slaveId < -9.007199254740992E15 || this->slaveId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightResumeSlaveInfo -"<<"Forbidden value (" << this->slaveId << ") on element slaveId.";
  }
  else
  {
    param1->writeDouble(this->slaveId);
    param1->writeShort((short)this->spellCooldowns.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->spellCooldowns.size())
    {
      (this->spellCooldowns[_loc2_]).serializeAs_GameFightSpellCooldown(param1);
      _loc2_++;
    }
    if(this->summonCount < 0)
    {
      qDebug()<<"ERREUR - GameFightResumeSlaveInfo -"<<"Forbidden value (" << this->summonCount << ") on element summonCount.";
    }
    else
    {
      param1->writeByte(this->summonCount);
      if(this->bombCount < 0)
      {
        qDebug()<<"ERREUR - GameFightResumeSlaveInfo -"<<"Forbidden value (" << this->bombCount << ") on element bombCount.";
      }
      else
      {
        param1->writeByte(this->bombCount);
        return;
      }
    }
  }
}

void GameFightResumeSlaveInfo::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightResumeSlaveInfo(param1);
}

void GameFightResumeSlaveInfo::deserializeAs_GameFightResumeSlaveInfo(Reader *param1)
{
  GameFightSpellCooldown _loc4_ ;
  this->slaveId = param1->readDouble();
  if(this->slaveId < -9.007199254740992E15 || this->slaveId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightResumeSlaveInfo -"<<"Forbidden value (" << this->slaveId << ") on element of GameFightResumeSlaveInfo.slaveId.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = GameFightSpellCooldown();
      _loc4_.deserialize(param1);
      this->spellCooldowns.append(_loc4_);
      _loc3_++;
    }
    this->summonCount = param1->readByte();
    if(this->summonCount < 0)
    {
      qDebug()<<"ERREUR - GameFightResumeSlaveInfo -"<<"Forbidden value (" << this->summonCount << ") on element of GameFightResumeSlaveInfo.summonCount.";
    }
    else
    {
      this->bombCount = param1->readByte();
      if(this->bombCount < 0)
      {
        qDebug()<<"ERREUR - GameFightResumeSlaveInfo -"<<"Forbidden value (" << this->bombCount << ") on element of GameFightResumeSlaveInfo.bombCount.";
      }
      else
      {
        return;
      }
    }
  }
}

GameFightResumeSlaveInfo::GameFightResumeSlaveInfo()
{
  m_types<<ClassEnum::GAMEFIGHTRESUMESLAVEINFO;
}

bool GameFightResumeSlaveInfo::operator==(const GameFightResumeSlaveInfo &compared)
{
  if(slaveId == compared.slaveId)
  if(spellCooldowns == compared.spellCooldowns)
  if(summonCount == compared.summonCount)
  if(bombCount == compared.bombCount)
  return true;
  
  return false;
}

