#include "GameContextRemoveMultipleElementsWithEventsMessage.h"

void GameContextRemoveMultipleElementsWithEventsMessage::serialize(Writer *param1)
{
  this->serializeAs_GameContextRemoveMultipleElementsWithEventsMessage(param1);
}

void GameContextRemoveMultipleElementsWithEventsMessage::serializeAs_GameContextRemoveMultipleElementsWithEventsMessage(Writer *param1)
{
  GameContextRemoveMultipleElementsMessage::serializeAs_GameContextRemoveMultipleElementsMessage(param1);
  param1->writeShort((short)this->elementEventIds.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->elementEventIds.size())
  {
    if(this->elementEventIds[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - GameContextRemoveMultipleElementsWithEventsMessage -"<<"Forbidden value (" << this->elementEventIds[_loc2_] << ") on element 1 (starting at 1) of elementEventIds.";
    }
    else
    {
      param1->writeByte(this->elementEventIds[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void GameContextRemoveMultipleElementsWithEventsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameContextRemoveMultipleElementsWithEventsMessage(param1);
}

void GameContextRemoveMultipleElementsWithEventsMessage::deserializeAs_GameContextRemoveMultipleElementsWithEventsMessage(Reader *param1)
{
  uint _loc4_ = 0;
  GameContextRemoveMultipleElementsMessage::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readByte();
    if(_loc4_ < 0)
    {
      qDebug()<<"ERREUR - GameContextRemoveMultipleElementsWithEventsMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of elementEventIds.";
    }
    else
    {
      this->elementEventIds.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

GameContextRemoveMultipleElementsWithEventsMessage::GameContextRemoveMultipleElementsWithEventsMessage()
{
  m_type = MessageEnum::GAMECONTEXTREMOVEMULTIPLEELEMENTSWITHEVENTSMESSAGE;
}

