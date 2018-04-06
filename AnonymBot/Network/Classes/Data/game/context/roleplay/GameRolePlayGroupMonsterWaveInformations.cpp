#include "GameRolePlayGroupMonsterWaveInformations.h"

void GameRolePlayGroupMonsterWaveInformations::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayGroupMonsterWaveInformations(param1);
}

void GameRolePlayGroupMonsterWaveInformations::serializeAs_GameRolePlayGroupMonsterWaveInformations(Writer *param1)
{
  GameRolePlayGroupMonsterInformations::serializeAs_GameRolePlayGroupMonsterInformations(param1);
  if(this->nbWaves < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayGroupMonsterWaveInformations -"<<"Forbidden value (" << this->nbWaves << ") on element nbWaves.";
  }
  else
  {
    param1->writeByte(this->nbWaves);
    param1->writeShort((short)this->alternatives.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->alternatives.size())
    {
      param1->writeShort((short)qSharedPointerCast<GroupMonsterStaticInformations>(this->alternatives[_loc2_])->getTypes().last());
      qSharedPointerCast<GroupMonsterStaticInformations>(this->alternatives[_loc2_])->serialize(param1);
      _loc2_++;
    }
    return;
  }
}

void GameRolePlayGroupMonsterWaveInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayGroupMonsterWaveInformations(param1);
}

void GameRolePlayGroupMonsterWaveInformations::deserializeAs_GameRolePlayGroupMonsterWaveInformations(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<GroupMonsterStaticInformations> _loc5_ ;
  GameRolePlayGroupMonsterInformations::deserialize(param1);
  this->nbWaves = param1->readByte();
  if(this->nbWaves < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayGroupMonsterWaveInformations -"<<"Forbidden value (" << this->nbWaves << ") on element of GameRolePlayGroupMonsterWaveInformations.nbWaves.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = param1->readUShort();
      _loc5_ = qSharedPointerCast<GroupMonsterStaticInformations>(ClassManagerSingleton::get()->getClass(_loc4_));
      _loc5_->deserialize(param1);
      this->alternatives.append(_loc5_);
      _loc3_++;
    }
    return;
  }
}

GameRolePlayGroupMonsterWaveInformations::GameRolePlayGroupMonsterWaveInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYGROUPMONSTERWAVEINFORMATIONS;
}

bool GameRolePlayGroupMonsterWaveInformations::operator==(const GameRolePlayGroupMonsterWaveInformations &compared)
{
  if(nbWaves == compared.nbWaves)
  if(alternatives == compared.alternatives)
  return true;
  
  return false;
}

