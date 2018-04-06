#include "GameMapMovementMessage.h"

void GameMapMovementMessage::serialize(Writer *param1)
{
  this->serializeAs_GameMapMovementMessage(param1);
}

void GameMapMovementMessage::serializeAs_GameMapMovementMessage(Writer *param1)
{
  param1->writeShort((short)this->keyMovements.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->keyMovements.size())
  {
    if(this->keyMovements[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - GameMapMovementMessage -"<<"Forbidden value (" << this->keyMovements[_loc2_] << ") on element 1 (starting at 1) of keyMovements.";
    }
    else
    {
      param1->writeShort((short)this->keyMovements[_loc2_]);
      _loc2_++;
      continue;
    }
  }
  if(this->actorId < -9.007199254740992E15 || this->actorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameMapMovementMessage -"<<"Forbidden value (" << this->actorId << ") on element actorId.";
  }
  else
  {
    param1->writeDouble(this->actorId);
    return;
  }
}

void GameMapMovementMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameMapMovementMessage(param1);
}

void GameMapMovementMessage::deserializeAs_GameMapMovementMessage(Reader *param1)
{
  uint _loc4_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readShort();
    if(_loc4_ < 0)
    {
      qDebug()<<"ERREUR - GameMapMovementMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of keyMovements.";
    }
    else
    {
      this->keyMovements.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
  this->actorId = param1->readDouble();
  if(this->actorId < -9.007199254740992E15 || this->actorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameMapMovementMessage -"<<"Forbidden value (" << this->actorId << ") on element of GameMapMovementMessage.actorId.";
  }
  else
  {
    return;
  }
}

GameMapMovementMessage::GameMapMovementMessage()
{
  m_type = MessageEnum::GAMEMAPMOVEMENTMESSAGE;
}

