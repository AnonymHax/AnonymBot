#include "GameRolePlayHumanoidInformations.h"

void GameRolePlayHumanoidInformations::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayHumanoidInformations(param1);
}

void GameRolePlayHumanoidInformations::serializeAs_GameRolePlayHumanoidInformations(Writer *param1)
{
  GameRolePlayNamedActorInformations::serializeAs_GameRolePlayNamedActorInformations(param1);
  param1->writeShort((short)this->humanoidInfo->getTypes().last());
  this->humanoidInfo->serialize(param1);
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayHumanoidInformations -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
  }
  else
  {
    param1->writeInt((int)this->accountId);
    return;
  }
}

void GameRolePlayHumanoidInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayHumanoidInformations(param1);
}

void GameRolePlayHumanoidInformations::deserializeAs_GameRolePlayHumanoidInformations(Reader *param1)
{
  GameRolePlayNamedActorInformations::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  this->humanoidInfo = qSharedPointerCast<HumanInformations>(ClassManagerSingleton::get()->getClass(_loc2_));
  this->humanoidInfo->deserialize(param1);
  this->accountId = param1->readInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayHumanoidInformations -"<<"Forbidden value (" << this->accountId << ") on element of GameRolePlayHumanoidInformations.accountId.";
  }
  else
  {
    return;
  }
}

GameRolePlayHumanoidInformations::GameRolePlayHumanoidInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYHUMANOIDINFORMATIONS;
}

bool GameRolePlayHumanoidInformations::operator==(const GameRolePlayHumanoidInformations &compared)
{
  if(humanoidInfo == compared.humanoidInfo)
  if(accountId == compared.accountId)
  return true;
  
  return false;
}

