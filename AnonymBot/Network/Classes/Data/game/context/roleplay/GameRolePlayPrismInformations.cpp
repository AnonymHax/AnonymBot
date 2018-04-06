#include "GameRolePlayPrismInformations.h"

void GameRolePlayPrismInformations::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayPrismInformations(param1);
}

void GameRolePlayPrismInformations::serializeAs_GameRolePlayPrismInformations(Writer *param1)
{
  GameRolePlayActorInformations::serializeAs_GameRolePlayActorInformations(param1);
  param1->writeShort((short)this->prism->getTypes().last());
  this->prism->serialize(param1);
}

void GameRolePlayPrismInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayPrismInformations(param1);
}

void GameRolePlayPrismInformations::deserializeAs_GameRolePlayPrismInformations(Reader *param1)
{
  GameRolePlayActorInformations::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  this->prism = qSharedPointerCast<PrismInformation>(ClassManagerSingleton::get()->getClass(_loc2_));
  this->prism->deserialize(param1);
}

GameRolePlayPrismInformations::GameRolePlayPrismInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYPRISMINFORMATIONS;
}

bool GameRolePlayPrismInformations::operator==(const GameRolePlayPrismInformations &compared)
{
  if(prism == compared.prism)
  return true;
  
  return false;
}

