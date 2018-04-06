#include "GameFightFighterLightInformations.h"

void GameFightFighterLightInformations::serialize(Writer *param1)
{
  this->serializeAs_GameFightFighterLightInformations(param1);
}

void GameFightFighterLightInformations::serializeAs_GameFightFighterLightInformations(Writer *param1)
{
  uint _loc2_ = 0;
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->sex);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->alive);
  param1->writeByte(_loc2_);
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightFighterLightInformations -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeDouble(this->id);
    if(this->wave < 0)
    {
      qDebug()<<"ERREUR - GameFightFighterLightInformations -"<<"Forbidden value (" << this->wave << ") on element wave.";
    }
    else
    {
      param1->writeByte(this->wave);
      if(this->level < 0)
      {
        qDebug()<<"ERREUR - GameFightFighterLightInformations -"<<"Forbidden value (" << this->level << ") on element level.";
      }
      else
      {
        param1->writeVarShort((int)this->level);
        param1->writeByte(this->breed);
        return;
      }
    }
  }
}

void GameFightFighterLightInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightFighterLightInformations(param1);
}

void GameFightFighterLightInformations::deserializeAs_GameFightFighterLightInformations(Reader *param1)
{
  uint _loc2_ = param1->readByte();
  this->sex = BooleanByteWrapper::getFlag(_loc2_, 0);
  this->alive = BooleanByteWrapper::getFlag(_loc2_, 1);
  this->id = param1->readDouble();
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightFighterLightInformations -"<<"Forbidden value (" << this->id << ") on element of GameFightFighterLightInformations.id.";
  }
  else
  {
    this->wave = param1->readByte();
    if(this->wave < 0)
    {
      qDebug()<<"ERREUR - GameFightFighterLightInformations -"<<"Forbidden value (" << this->wave << ") on element of GameFightFighterLightInformations.wave.";
    }
    else
    {
      this->level = param1->readVarUhShort();
      if(this->level < 0)
      {
        qDebug()<<"ERREUR - GameFightFighterLightInformations -"<<"Forbidden value (" << this->level << ") on element of GameFightFighterLightInformations.level.";
      }
      else
      {
        this->breed = param1->readByte();
        return;
      }
    }
  }
}

GameFightFighterLightInformations::GameFightFighterLightInformations()
{
  m_types<<ClassEnum::GAMEFIGHTFIGHTERLIGHTINFORMATIONS;
}

bool GameFightFighterLightInformations::operator==(const GameFightFighterLightInformations &compared)
{
  if(id == compared.id)
  if(wave == compared.wave)
  if(level == compared.level)
  if(breed == compared.breed)
  if(sex == compared.sex)
  if(alive == compared.alive)
  return true;
  
  return false;
}

