#include "GameEntitiesDispositionMessage.h"

void GameEntitiesDispositionMessage::serialize(Writer *param1)
{
  this->serializeAs_GameEntitiesDispositionMessage(param1);
}

void GameEntitiesDispositionMessage::serializeAs_GameEntitiesDispositionMessage(Writer *param1)
{
  param1->writeShort((short)this->dispositions.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->dispositions.size())
  {
    qSharedPointerCast<IdentifiedEntityDispositionInformations>(this->dispositions[_loc2_])->serializeAs_IdentifiedEntityDispositionInformations(param1);
    _loc2_++;
  }
}

void GameEntitiesDispositionMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameEntitiesDispositionMessage(param1);
}

void GameEntitiesDispositionMessage::deserializeAs_GameEntitiesDispositionMessage(Reader *param1)
{
  QSharedPointer<IdentifiedEntityDispositionInformations> _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = QSharedPointer<IdentifiedEntityDispositionInformations>(new IdentifiedEntityDispositionInformations() );
    _loc4_->deserialize(param1);
    this->dispositions.append(_loc4_);
    _loc3_++;
  }
}

GameEntitiesDispositionMessage::GameEntitiesDispositionMessage()
{
  m_type = MessageEnum::GAMEENTITIESDISPOSITIONMESSAGE;
}

