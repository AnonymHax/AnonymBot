#include "DungeonPartyFinderAvailableDungeonsMessage.h"

void DungeonPartyFinderAvailableDungeonsMessage::serialize(Writer *param1)
{
  this->serializeAs_DungeonPartyFinderAvailableDungeonsMessage(param1);
}

void DungeonPartyFinderAvailableDungeonsMessage::serializeAs_DungeonPartyFinderAvailableDungeonsMessage(Writer *param1)
{
  param1->writeShort((short)this->dungeonIds.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->dungeonIds.size())
  {
    if(this->dungeonIds[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - DungeonPartyFinderAvailableDungeonsMessage -"<<"Forbidden value (" << this->dungeonIds[_loc2_] << ") on element 1 (starting at 1) of dungeonIds.";
    }
    else
    {
      param1->writeVarShort((int)this->dungeonIds[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void DungeonPartyFinderAvailableDungeonsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DungeonPartyFinderAvailableDungeonsMessage(param1);
}

void DungeonPartyFinderAvailableDungeonsMessage::deserializeAs_DungeonPartyFinderAvailableDungeonsMessage(Reader *param1)
{
  uint _loc4_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readVarUhShort();
    if(_loc4_ < 0)
    {
      qDebug()<<"ERREUR - DungeonPartyFinderAvailableDungeonsMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of dungeonIds.";
    }
    else
    {
      this->dungeonIds.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

DungeonPartyFinderAvailableDungeonsMessage::DungeonPartyFinderAvailableDungeonsMessage()
{
  m_type = MessageEnum::DUNGEONPARTYFINDERAVAILABLEDUNGEONSMESSAGE;
}

