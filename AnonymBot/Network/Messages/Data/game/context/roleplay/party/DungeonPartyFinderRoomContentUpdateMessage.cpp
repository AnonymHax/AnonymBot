#include "DungeonPartyFinderRoomContentUpdateMessage.h"

void DungeonPartyFinderRoomContentUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_DungeonPartyFinderRoomContentUpdateMessage(param1);
}

void DungeonPartyFinderRoomContentUpdateMessage::serializeAs_DungeonPartyFinderRoomContentUpdateMessage(Writer *param1)
{
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderRoomContentUpdateMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  else
  {
    param1->writeVarShort((int)this->dungeonId);
    param1->writeShort((short)this->addedPlayers.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->addedPlayers.size())
    {
      (this->addedPlayers[_loc2_]).serializeAs_DungeonPartyFinderPlayer(param1);
      _loc2_++;
    }
    param1->writeShort((short)this->removedPlayersIds.size());
    uint _loc3_ = 0;
    while(_loc3_ < this->removedPlayersIds.size())
    {
      if(this->removedPlayersIds[_loc3_] < 0 || this->removedPlayersIds[_loc3_] > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - DungeonPartyFinderRoomContentUpdateMessage -"<<"Forbidden value (" << this->removedPlayersIds[_loc3_] << ") on element 3 (starting at 1) of removedPlayersIds.";
      }
      else
      {
        param1->writeVarLong((double)this->removedPlayersIds[_loc3_]);
        _loc3_++;
        continue;
      }
    }
    return;
  }
}

void DungeonPartyFinderRoomContentUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DungeonPartyFinderRoomContentUpdateMessage(param1);
}

void DungeonPartyFinderRoomContentUpdateMessage::deserializeAs_DungeonPartyFinderRoomContentUpdateMessage(Reader *param1)
{
  DungeonPartyFinderPlayer _loc6_ ;
  auto _loc7_ = NULL;
  this->dungeonId = param1->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderRoomContentUpdateMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of DungeonPartyFinderRoomContentUpdateMessage.dungeonId.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc6_ = DungeonPartyFinderPlayer();
      _loc6_.deserialize(param1);
      this->addedPlayers.append(_loc6_);
      _loc3_++;
    }
    uint _loc4_ = param1->readUShort();
    uint _loc5_ = 0;
    while(_loc5_ < _loc4_)
    {
      _loc7_ = param1->readVarUhLong();
      if(_loc7_ < 0 || _loc7_ > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - DungeonPartyFinderRoomContentUpdateMessage -"<<"Forbidden value (" << _loc7_ << ") on elements of removedPlayersIds.";
      }
      else
      {
        this->removedPlayersIds.append(_loc7_);
        _loc5_++;
        continue;
      }
    }
    return;
  }
}

DungeonPartyFinderRoomContentUpdateMessage::DungeonPartyFinderRoomContentUpdateMessage()
{
  m_type = MessageEnum::DUNGEONPARTYFINDERROOMCONTENTUPDATEMESSAGE;
}

