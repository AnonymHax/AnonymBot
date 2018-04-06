#include "GameEntityDispositionMessage.h"

void GameEntityDispositionMessage::serialize(Writer *param1)
{
  this->serializeAs_GameEntityDispositionMessage(param1);
}

void GameEntityDispositionMessage::serializeAs_GameEntityDispositionMessage(Writer *param1)
{
  this->disposition->serializeAs_IdentifiedEntityDispositionInformations(param1);
}

void GameEntityDispositionMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameEntityDispositionMessage(param1);
}

void GameEntityDispositionMessage::deserializeAs_GameEntityDispositionMessage(Reader *param1)
{
  this->disposition = QSharedPointer<IdentifiedEntityDispositionInformations>(new IdentifiedEntityDispositionInformations() );
  this->disposition->deserialize(param1);
}

GameEntityDispositionMessage::GameEntityDispositionMessage()
{
  m_type = MessageEnum::GAMEENTITYDISPOSITIONMESSAGE;
}

