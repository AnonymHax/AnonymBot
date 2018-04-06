#include "GameMapMovementRequestMessage.h"

void GameMapMovementRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_GameMapMovementRequestMessage(param1);
}

void GameMapMovementRequestMessage::serializeAs_GameMapMovementRequestMessage(Writer *param1)
{
  param1->writeShort((short)this->keyMovements.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->keyMovements.size())
  {
    if(this->keyMovements[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - GameMapMovementRequestMessage -"<<"Forbidden value (" << this->keyMovements[_loc2_] << ") on element 1 (starting at 1) of keyMovements.";
    }
    else
    {
      param1->writeShort((short)this->keyMovements[_loc2_]);
      _loc2_++;
      continue;
    }
  }
  if(this->mapId < 0)
  {
    qDebug()<<"ERREUR - GameMapMovementRequestMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  else
  {
    param1->writeInt((int)this->mapId);
    return;
  }
}

void GameMapMovementRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameMapMovementRequestMessage(param1);
}

void GameMapMovementRequestMessage::deserializeAs_GameMapMovementRequestMessage(Reader *param1)
{
  uint _loc4_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readShort();
    if(_loc4_ < 0)
    {
      qDebug()<<"ERREUR - GameMapMovementRequestMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of keyMovements.";
    }
    else
    {
      this->keyMovements.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
  this->mapId = param1->readInt();
  if(this->mapId < 0)
  {
    qDebug()<<"ERREUR - GameMapMovementRequestMessage -"<<"Forbidden value (" << this->mapId << ") on element of GameMapMovementRequestMessage.mapId.";
  }
  else
  {
    return;
  }
}

GameMapMovementRequestMessage::GameMapMovementRequestMessage()
{
  m_type = MessageEnum::GAMEMAPMOVEMENTREQUESTMESSAGE;
  m_needsHash = true;
}

