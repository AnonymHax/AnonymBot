#include "ChallengeTargetsListMessage.h"

void ChallengeTargetsListMessage::serialize(Writer *param1)
{
  this->serializeAs_ChallengeTargetsListMessage(param1);
}

void ChallengeTargetsListMessage::serializeAs_ChallengeTargetsListMessage(Writer *param1)
{
  param1->writeShort((short)this->targetIds.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->targetIds.size())
  {
    if(this->targetIds[_loc2_] < -9.007199254740992E15 || this->targetIds[_loc2_] > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - ChallengeTargetsListMessage -"<<"Forbidden value (" << this->targetIds[_loc2_] << ") on element 1 (starting at 1) of targetIds.";
    }
    else
    {
      param1->writeDouble(this->targetIds[_loc2_]);
      _loc2_++;
      continue;
    }
  }
  param1->writeShort((short)this->targetCells.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->targetCells.size())
  {
    if(this->targetCells[_loc3_] < -1 || this->targetCells[_loc3_] > 559)
    {
      qDebug()<<"ERREUR - ChallengeTargetsListMessage -"<<"Forbidden value (" << this->targetCells[_loc3_] << ") on element 2 (starting at 1) of targetCells.";
    }
    else
    {
      param1->writeShort((short)this->targetCells[_loc3_]);
      _loc3_++;
      continue;
    }
  }
}

void ChallengeTargetsListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChallengeTargetsListMessage(param1);
}

void ChallengeTargetsListMessage::deserializeAs_ChallengeTargetsListMessage(Reader *param1)
{
  auto _loc6_ = NULL;
  auto _loc7_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc6_ = param1->readDouble();
    if(_loc6_ < -9.007199254740992E15 || _loc6_ > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - ChallengeTargetsListMessage -"<<"Forbidden value (" << _loc6_ << ") on elements of targetIds.";
    }
    else
    {
      this->targetIds.append(_loc6_);
      _loc3_++;
      continue;
    }
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc7_ = param1->readShort();
    if(_loc7_ < -1 || _loc7_ > 559)
    {
      qDebug()<<"ERREUR - ChallengeTargetsListMessage -"<<"Forbidden value (" << _loc7_ << ") on elements of targetCells.";
    }
    else
    {
      this->targetCells.append(_loc7_);
      _loc5_++;
      continue;
    }
  }
}

ChallengeTargetsListMessage::ChallengeTargetsListMessage()
{
  m_type = MessageEnum::CHALLENGETARGETSLISTMESSAGE;
}

