#include "GameFightPlacementSwapPositionsMessage.h"

void GameFightPlacementSwapPositionsMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightPlacementSwapPositionsMessage(param1);
}

void GameFightPlacementSwapPositionsMessage::serializeAs_GameFightPlacementSwapPositionsMessage(Writer *param1)
{
  uint _loc2_ = 0;
  while(_loc2_ < 2)
  {
    this->dispositions[_loc2_]->serializeAs_IdentifiedEntityDispositionInformations(param1);
    _loc2_++;
  }
}

void GameFightPlacementSwapPositionsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightPlacementSwapPositionsMessage(param1);
}

void GameFightPlacementSwapPositionsMessage::deserializeAs_GameFightPlacementSwapPositionsMessage(Reader *param1)
{
  uint _loc2_ = 0;
  while(_loc2_ < 2)
  {
    this->dispositions<<QSharedPointer<IdentifiedEntityDispositionInformations>(new IdentifiedEntityDispositionInformations() );
    this->dispositions[_loc2_]->deserialize(param1);
    _loc2_++;
  }
}

GameFightPlacementSwapPositionsMessage::GameFightPlacementSwapPositionsMessage()
{
  m_type = MessageEnum::GAMEFIGHTPLACEMENTSWAPPOSITIONSMESSAGE;
}

