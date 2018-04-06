#include "GameFightPlacementPossiblePositionsMessage.h"

void GameFightPlacementPossiblePositionsMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightPlacementPossiblePositionsMessage(param1);
}

void GameFightPlacementPossiblePositionsMessage::serializeAs_GameFightPlacementPossiblePositionsMessage(Writer *param1)
{
  param1->writeShort((short)this->positionsForChallengers.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->positionsForChallengers.size())
  {
    if(this->positionsForChallengers[_loc2_] < 0 || this->positionsForChallengers[_loc2_] > 559)
    {
      qDebug()<<"ERREUR - GameFightPlacementPossiblePositionsMessage -"<<"Forbidden value (" << this->positionsForChallengers[_loc2_] << ") on element 1 (starting at 1) of positionsForChallengers.";
    }
    else
    {
      param1->writeVarShort((int)this->positionsForChallengers[_loc2_]);
      _loc2_++;
      continue;
    }
  }
  param1->writeShort((short)this->positionsForDefenders.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->positionsForDefenders.size())
  {
    if(this->positionsForDefenders[_loc3_] < 0 || this->positionsForDefenders[_loc3_] > 559)
    {
      qDebug()<<"ERREUR - GameFightPlacementPossiblePositionsMessage -"<<"Forbidden value (" << this->positionsForDefenders[_loc3_] << ") on element 2 (starting at 1) of positionsForDefenders.";
    }
    else
    {
      param1->writeVarShort((int)this->positionsForDefenders[_loc3_]);
      _loc3_++;
      continue;
    }
  }
  param1->writeByte(this->teamNumber);
}

void GameFightPlacementPossiblePositionsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightPlacementPossiblePositionsMessage(param1);
}

void GameFightPlacementPossiblePositionsMessage::deserializeAs_GameFightPlacementPossiblePositionsMessage(Reader *param1)
{
  uint _loc6_ = 0;
  uint _loc7_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc6_ = param1->readVarUhShort();
    if(_loc6_ < 0 || _loc6_ > 559)
    {
      qDebug()<<"ERREUR - GameFightPlacementPossiblePositionsMessage -"<<"Forbidden value (" << _loc6_ << ") on elements of positionsForChallengers.";
    }
    else
    {
      this->positionsForChallengers.append(_loc6_);
      _loc3_++;
      continue;
    }
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc7_ = param1->readVarUhShort();
    if(_loc7_ < 0 || _loc7_ > 559)
    {
      qDebug()<<"ERREUR - GameFightPlacementPossiblePositionsMessage -"<<"Forbidden value (" << _loc7_ << ") on elements of positionsForDefenders.";
    }
    else
    {
      this->positionsForDefenders.append(_loc7_);
      _loc5_++;
      continue;
    }
  }
  this->teamNumber = param1->readByte();
  if(this->teamNumber < 0)
  {
    qDebug()<<"ERREUR - GameFightPlacementPossiblePositionsMessage -"<<"Forbidden value (" << this->teamNumber << ") on element of GameFightPlacementPossiblePositionsMessage.teamNumber.";
  }
  else
  {
    return;
  }
}

GameFightPlacementPossiblePositionsMessage::GameFightPlacementPossiblePositionsMessage()
{
  m_type = MessageEnum::GAMEFIGHTPLACEMENTPOSSIBLEPOSITIONSMESSAGE;
}

