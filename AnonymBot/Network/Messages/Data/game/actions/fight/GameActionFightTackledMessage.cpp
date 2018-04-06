#include "GameActionFightTackledMessage.h"

void GameActionFightTackledMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightTackledMessage(param1);
}

void GameActionFightTackledMessage::serializeAs_GameActionFightTackledMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  param1->writeShort((short)this->tacklersIds.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->tacklersIds.size())
  {
    if(this->tacklersIds[_loc2_] < -9.007199254740992E15 || this->tacklersIds[_loc2_] > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameActionFightTackledMessage -"<<"Forbidden value (" << this->tacklersIds[_loc2_] << ") on element 1 (starting at 1) of tacklersIds.";
    }
    else
    {
      param1->writeDouble(this->tacklersIds[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void GameActionFightTackledMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightTackledMessage(param1);
}

void GameActionFightTackledMessage::deserializeAs_GameActionFightTackledMessage(Reader *param1)
{
  auto _loc4_ = NULL;
  AbstractGameActionMessage::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readDouble();
    if(_loc4_ < -9.007199254740992E15 || _loc4_ > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameActionFightTackledMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of tacklersIds.";
    }
    else
    {
      this->tacklersIds.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

GameActionFightTackledMessage::GameActionFightTackledMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTTACKLEDMESSAGE;
}

