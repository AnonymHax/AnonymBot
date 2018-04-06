#include "GameMapChangeOrientationMessage.h"

void GameMapChangeOrientationMessage::serialize(Writer *param1)
{
  this->serializeAs_GameMapChangeOrientationMessage(param1);
}

void GameMapChangeOrientationMessage::serializeAs_GameMapChangeOrientationMessage(Writer *param1)
{
  this->orientation.serializeAs_ActorOrientation(param1);
}

void GameMapChangeOrientationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameMapChangeOrientationMessage(param1);
}

void GameMapChangeOrientationMessage::deserializeAs_GameMapChangeOrientationMessage(Reader *param1)
{
  this->orientation = ActorOrientation();
  this->orientation.deserialize(param1);
}

GameMapChangeOrientationMessage::GameMapChangeOrientationMessage()
{
  m_type = MessageEnum::GAMEMAPCHANGEORIENTATIONMESSAGE;
}

