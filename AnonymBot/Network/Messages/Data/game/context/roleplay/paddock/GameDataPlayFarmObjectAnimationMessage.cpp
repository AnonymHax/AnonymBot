#include "GameDataPlayFarmObjectAnimationMessage.h"

void GameDataPlayFarmObjectAnimationMessage::serialize(Writer *param1)
{
  this->serializeAs_GameDataPlayFarmObjectAnimationMessage(param1);
}

void GameDataPlayFarmObjectAnimationMessage::serializeAs_GameDataPlayFarmObjectAnimationMessage(Writer *param1)
{
  param1->writeShort((short)this->cellId.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->cellId.size())
  {
    if(this->cellId[_loc2_] < 0 || this->cellId[_loc2_] > 559)
    {
      qDebug()<<"ERREUR - GameDataPlayFarmObjectAnimationMessage -"<<"Forbidden value (" << this->cellId[_loc2_] << ") on element 1 (starting at 1) of cellId.";
    }
    else
    {
      param1->writeVarShort((int)this->cellId[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void GameDataPlayFarmObjectAnimationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameDataPlayFarmObjectAnimationMessage(param1);
}

void GameDataPlayFarmObjectAnimationMessage::deserializeAs_GameDataPlayFarmObjectAnimationMessage(Reader *param1)
{
  uint _loc4_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readVarUhShort();
    if(_loc4_ < 0 || _loc4_ > 559)
    {
      qDebug()<<"ERREUR - GameDataPlayFarmObjectAnimationMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of cellId.";
    }
    else
    {
      this->cellId.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

GameDataPlayFarmObjectAnimationMessage::GameDataPlayFarmObjectAnimationMessage()
{
  m_type = MessageEnum::GAMEDATAPLAYFARMOBJECTANIMATIONMESSAGE;
}

