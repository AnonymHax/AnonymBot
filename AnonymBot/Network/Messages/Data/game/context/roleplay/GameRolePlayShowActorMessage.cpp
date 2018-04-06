#include "GameRolePlayShowActorMessage.h"

void GameRolePlayShowActorMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayShowActorMessage(param1);
}

void GameRolePlayShowActorMessage::serializeAs_GameRolePlayShowActorMessage(Writer *param1)
{
  param1->writeShort((short)this->informations->getTypes().last());
  this->informations->serialize(param1);
}

void GameRolePlayShowActorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayShowActorMessage(param1);
}

void GameRolePlayShowActorMessage::deserializeAs_GameRolePlayShowActorMessage(Reader *param1)
{
  uint _loc2_ = param1->readUShort();
  this->informations = qSharedPointerCast<GameRolePlayActorInformations>(ClassManagerSingleton::get()->getClass(_loc2_));
  this->informations->deserialize(param1);
}

GameRolePlayShowActorMessage::GameRolePlayShowActorMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYSHOWACTORMESSAGE;
}

