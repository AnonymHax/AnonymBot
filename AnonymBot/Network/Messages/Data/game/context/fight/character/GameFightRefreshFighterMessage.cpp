#include "GameFightRefreshFighterMessage.h"

void GameFightRefreshFighterMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightRefreshFighterMessage(param1);
}

void GameFightRefreshFighterMessage::serializeAs_GameFightRefreshFighterMessage(Writer *param1)
{
  param1->writeShort((short)this->informations->getTypes().last());
  this->informations->serialize(param1);
}

void GameFightRefreshFighterMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightRefreshFighterMessage(param1);
}

void GameFightRefreshFighterMessage::deserializeAs_GameFightRefreshFighterMessage(Reader *param1)
{
  uint _loc2_ = param1->readUShort();
  this->informations = qSharedPointerCast<GameContextActorInformations>(ClassManagerSingleton::get()->getClass(_loc2_));
  this->informations->deserialize(param1);
}

GameFightRefreshFighterMessage::GameFightRefreshFighterMessage()
{
  m_type = MessageEnum::GAMEFIGHTREFRESHFIGHTERMESSAGE;
}

