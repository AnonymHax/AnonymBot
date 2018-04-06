#include "GameFightShowFighterRandomStaticPoseMessage.h"

void GameFightShowFighterRandomStaticPoseMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightShowFighterRandomStaticPoseMessage(param1);
}

void GameFightShowFighterRandomStaticPoseMessage::serializeAs_GameFightShowFighterRandomStaticPoseMessage(Writer *param1)
{
  GameFightShowFighterMessage::serializeAs_GameFightShowFighterMessage(param1);
}

void GameFightShowFighterRandomStaticPoseMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightShowFighterRandomStaticPoseMessage(param1);
}

void GameFightShowFighterRandomStaticPoseMessage::deserializeAs_GameFightShowFighterRandomStaticPoseMessage(Reader *param1)
{
  GameFightShowFighterMessage::deserialize(param1);
}

GameFightShowFighterRandomStaticPoseMessage::GameFightShowFighterRandomStaticPoseMessage()
{
  m_type = MessageEnum::GAMEFIGHTSHOWFIGHTERRANDOMSTATICPOSEMESSAGE;
}

