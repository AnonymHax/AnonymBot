#include "GameCautiousMapMovementRequestMessage.h"

void GameCautiousMapMovementRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_GameCautiousMapMovementRequestMessage(param1);
}

void GameCautiousMapMovementRequestMessage::serializeAs_GameCautiousMapMovementRequestMessage(Writer *param1)
{
  GameMapMovementRequestMessage::serializeAs_GameMapMovementRequestMessage(param1);
}

void GameCautiousMapMovementRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameCautiousMapMovementRequestMessage(param1);
}

void GameCautiousMapMovementRequestMessage::deserializeAs_GameCautiousMapMovementRequestMessage(Reader *param1)
{
  GameMapMovementRequestMessage::deserialize(param1);
}

GameCautiousMapMovementRequestMessage::GameCautiousMapMovementRequestMessage()
{
  m_type = MessageEnum::GAMECAUTIOUSMAPMOVEMENTREQUESTMESSAGE;
  m_needsHash = true;
}

