#include "GameFightFighterInformations.h"

void GameFightFighterInformations::serialize(Writer *param1)
{
  this->serializeAs_GameFightFighterInformations(param1);
}

void GameFightFighterInformations::serializeAs_GameFightFighterInformations(Writer *param1)
{
  GameContextActorInformations::serializeAs_GameContextActorInformations(param1);
  param1->writeByte(this->teamId);
  if(this->wave < 0)
  {
    qDebug()<<"ERREUR - GameFightFighterInformations -"<<"Forbidden value (" << this->wave << ") on element wave.";
  }
  else
  {
    param1->writeByte(this->wave);
    param1->writeBool(this->alive);
    param1->writeShort((short)this->stats->getTypes().last());
    this->stats->serialize(param1);
    param1->writeShort((short)this->previousPositions.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->previousPositions.size())
    {
      if(this->previousPositions[_loc2_] < 0 || this->previousPositions[_loc2_] > 559)
      {
        qDebug()<<"ERREUR - GameFightFighterInformations -"<<"Forbidden value (" << this->previousPositions[_loc2_] << ") on element 5 (starting at 1) of previousPositions.";
      }
      else
      {
        param1->writeVarShort((int)this->previousPositions[_loc2_]);
        _loc2_++;
        continue;
      }
    }
    return;
  }
}

void GameFightFighterInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightFighterInformations(param1);
}

void GameFightFighterInformations::deserializeAs_GameFightFighterInformations(Reader *param1)
{
  uint _loc5_ = 0;
  GameContextActorInformations::deserialize(param1);
  this->teamId = param1->readByte();
  if(this->teamId < 0)
  {
    qDebug()<<"ERREUR - GameFightFighterInformations -"<<"Forbidden value (" << this->teamId << ") on element of GameFightFighterInformations.teamId.";
  }
  else
  {
    this->wave = param1->readByte();
    if(this->wave < 0)
    {
      qDebug()<<"ERREUR - GameFightFighterInformations -"<<"Forbidden value (" << this->wave << ") on element of GameFightFighterInformations.wave.";
    }
    else
    {
      this->alive = param1->readBool();
      uint _loc2_ = param1->readUShort();
      this->stats = qSharedPointerCast<GameFightMinimalStats>(ClassManagerSingleton::get()->getClass(_loc2_));
      this->stats->deserialize(param1);
      uint _loc3_ = param1->readUShort();
      uint _loc4_ = 0;
      while(_loc4_ < _loc3_)
      {
        _loc5_ = param1->readVarUhShort();
        if(_loc5_ < 0 || _loc5_ > 559)
        {
          qDebug()<<"ERREUR - GameFightFighterInformations -"<<"Forbidden value (" << _loc5_ << ") on elements of previousPositions.";
        }
        else
        {
          this->previousPositions.append(_loc5_);
          _loc4_++;
          continue;
        }
      }
      return;
    }
  }
}

GameFightFighterInformations::GameFightFighterInformations()
{
  m_types<<ClassEnum::GAMEFIGHTFIGHTERINFORMATIONS;
}

bool GameFightFighterInformations::operator==(const GameFightFighterInformations &compared)
{
  if(teamId == compared.teamId)
  if(wave == compared.wave)
  if(alive == compared.alive)
  if(stats == compared.stats)
  if(previousPositions == compared.previousPositions)
  return true;
  
  return false;
}

