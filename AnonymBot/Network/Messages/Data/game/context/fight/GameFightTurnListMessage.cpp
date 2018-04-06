#include "GameFightTurnListMessage.h"

void GameFightTurnListMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightTurnListMessage(param1);
}

void GameFightTurnListMessage::serializeAs_GameFightTurnListMessage(Writer *param1)
{
  param1->writeShort((short)this->ids.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->ids.size())
  {
    if(this->ids[_loc2_] < -9.007199254740992E15 || this->ids[_loc2_] > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameFightTurnListMessage -"<<"Forbidden value (" << this->ids[_loc2_] << ") on element 1 (starting at 1) of ids.";
    }
    else
    {
      param1->writeDouble(this->ids[_loc2_]);
      _loc2_++;
      continue;
    }
  }
  param1->writeShort((short)this->deadsIds.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->deadsIds.size())
  {
    if(this->deadsIds[_loc3_] < -9.007199254740992E15 || this->deadsIds[_loc3_] > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameFightTurnListMessage -"<<"Forbidden value (" << this->deadsIds[_loc3_] << ") on element 2 (starting at 1) of deadsIds.";
    }
    else
    {
      param1->writeDouble(this->deadsIds[_loc3_]);
      _loc3_++;
      continue;
    }
  }
}

void GameFightTurnListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightTurnListMessage(param1);
}

void GameFightTurnListMessage::deserializeAs_GameFightTurnListMessage(Reader *param1)
{
  auto _loc6_ = NULL;
  auto _loc7_ = NULL;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc6_ = param1->readDouble();
    if(_loc6_ < -9.007199254740992E15 || _loc6_ > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameFightTurnListMessage -"<<"Forbidden value (" << _loc6_ << ") on elements of ids.";
    }
    else
    {
      this->ids.append(_loc6_);
      _loc3_++;
      continue;
    }
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc7_ = param1->readDouble();
    if(_loc7_ < -9.007199254740992E15 || _loc7_ > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameFightTurnListMessage -"<<"Forbidden value (" << _loc7_ << ") on elements of deadsIds.";
    }
    else
    {
      this->deadsIds.append(_loc7_);
      _loc5_++;
      continue;
    }
  }
}

GameFightTurnListMessage::GameFightTurnListMessage()
{
  m_type = MessageEnum::GAMEFIGHTTURNLISTMESSAGE;
}

