#include "DungeonPartyFinderRoomContentMessage.h"

void DungeonPartyFinderRoomContentMessage::serialize(Writer *param1)
{
  this->serializeAs_DungeonPartyFinderRoomContentMessage(param1);
}

void DungeonPartyFinderRoomContentMessage::serializeAs_DungeonPartyFinderRoomContentMessage(Writer *param1)
{
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderRoomContentMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  else
  {
    param1->writeVarShort((int)this->dungeonId);
    param1->writeShort((short)this->players.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->players.size())
    {
      (this->players[_loc2_]).serializeAs_DungeonPartyFinderPlayer(param1);
      _loc2_++;
    }
    return;
  }
}

void DungeonPartyFinderRoomContentMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DungeonPartyFinderRoomContentMessage(param1);
}

void DungeonPartyFinderRoomContentMessage::deserializeAs_DungeonPartyFinderRoomContentMessage(Reader *param1)
{
  DungeonPartyFinderPlayer _loc4_ ;
  this->dungeonId = param1->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderRoomContentMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of DungeonPartyFinderRoomContentMessage.dungeonId.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = DungeonPartyFinderPlayer();
      _loc4_.deserialize(param1);
      this->players.append(_loc4_);
      _loc3_++;
    }
    return;
  }
}

DungeonPartyFinderRoomContentMessage::DungeonPartyFinderRoomContentMessage()
{
  m_type = MessageEnum::DUNGEONPARTYFINDERROOMCONTENTMESSAGE;
}

