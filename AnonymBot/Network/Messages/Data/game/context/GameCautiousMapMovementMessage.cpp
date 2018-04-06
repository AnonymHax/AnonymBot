#include "GameCautiousMapMovementMessage.h"

void GameCautiousMapMovementMessage::serialize(Writer *param1)
{
  this->serializeAs_GameCautiousMapMovementMessage(param1);
}

void GameCautiousMapMovementMessage::serializeAs_GameCautiousMapMovementMessage(Writer *param1)
{
  GameMapMovementMessage::serializeAs_GameMapMovementMessage(param1);
}

void GameCautiousMapMovementMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameCautiousMapMovementMessage(param1);
}

void GameCautiousMapMovementMessage::deserializeAs_GameCautiousMapMovementMessage(Reader *param1)
{
  GameMapMovementMessage::deserialize(param1);
}

GameCautiousMapMovementMessage::GameCautiousMapMovementMessage()
{
  m_type = MessageEnum::GAMECAUTIOUSMAPMOVEMENTMESSAGE;
}

