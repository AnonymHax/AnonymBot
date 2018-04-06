#include "GameFightShowFighterMessage.h"

void GameFightShowFighterMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightShowFighterMessage(param1);
}

void GameFightShowFighterMessage::serializeAs_GameFightShowFighterMessage(Writer *param1)
{
  param1->writeShort((short)this->informations->getTypes().last());
  this->informations->serialize(param1);
}

void GameFightShowFighterMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightShowFighterMessage(param1);
}

void GameFightShowFighterMessage::deserializeAs_GameFightShowFighterMessage(Reader *param1)
{
  uint _loc2_ = param1->readUShort();
  this->informations = qSharedPointerCast<GameFightFighterInformations>(ClassManagerSingleton::get()->getClass(_loc2_));
  this->informations->deserialize(param1);
}

GameFightShowFighterMessage::GameFightShowFighterMessage()
{
  m_type = MessageEnum::GAMEFIGHTSHOWFIGHTERMESSAGE;
}

