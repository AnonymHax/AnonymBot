#include "DungeonPartyFinderRegisterRequestMessage.h"

void DungeonPartyFinderRegisterRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_DungeonPartyFinderRegisterRequestMessage(param1);
}

void DungeonPartyFinderRegisterRequestMessage::serializeAs_DungeonPartyFinderRegisterRequestMessage(Writer *param1)
{
  param1->writeShort((short)this->dungeonIds.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->dungeonIds.size())
  {
    if(this->dungeonIds[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - DungeonPartyFinderRegisterRequestMessage -"<<"Forbidden value (" << this->dungeonIds[_loc2_] << ") on element 1 (starting at 1) of dungeonIds.";
    }
    else
    {
      param1->writeVarShort((int)this->dungeonIds[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void DungeonPartyFinderRegisterRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DungeonPartyFinderRegisterRequestMessage(param1);
}

void DungeonPartyFinderRegisterRequestMessage::deserializeAs_DungeonPartyFinderRegisterRequestMessage(Reader *param1)
{
  uint _loc4_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readVarUhShort();
    if(_loc4_ < 0)
    {
      qDebug()<<"ERREUR - DungeonPartyFinderRegisterRequestMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of dungeonIds.";
    }
    else
    {
      this->dungeonIds.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

DungeonPartyFinderRegisterRequestMessage::DungeonPartyFinderRegisterRequestMessage()
{
  m_type = MessageEnum::DUNGEONPARTYFINDERREGISTERREQUESTMESSAGE;
}

