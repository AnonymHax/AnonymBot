#include "GameContextRemoveMultipleElementsMessage.h"

void GameContextRemoveMultipleElementsMessage::serialize(Writer *param1)
{
  this->serializeAs_GameContextRemoveMultipleElementsMessage(param1);
}

void GameContextRemoveMultipleElementsMessage::serializeAs_GameContextRemoveMultipleElementsMessage(Writer *param1)
{
  param1->writeShort((short)this->id.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->id.size())
  {
    if(this->id[_loc2_] < -9.007199254740992E15 || this->id[_loc2_] > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameContextRemoveMultipleElementsMessage -"<<"Forbidden value (" << this->id[_loc2_] << ") on element 1 (starting at 1) of id.";
    }
    else
    {
      param1->writeDouble(this->id[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void GameContextRemoveMultipleElementsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameContextRemoveMultipleElementsMessage(param1);
}

void GameContextRemoveMultipleElementsMessage::deserializeAs_GameContextRemoveMultipleElementsMessage(Reader *param1)
{
  auto _loc4_ = NULL;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readDouble();
    if(_loc4_ < -9.007199254740992E15 || _loc4_ > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameContextRemoveMultipleElementsMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of id.";
    }
    else
    {
      this->id.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

GameContextRemoveMultipleElementsMessage::GameContextRemoveMultipleElementsMessage()
{
  m_type = MessageEnum::GAMECONTEXTREMOVEMULTIPLEELEMENTSMESSAGE;
}

