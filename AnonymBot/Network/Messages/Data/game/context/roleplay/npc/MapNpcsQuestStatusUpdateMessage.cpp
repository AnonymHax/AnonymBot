#include "MapNpcsQuestStatusUpdateMessage.h"

void MapNpcsQuestStatusUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_MapNpcsQuestStatusUpdateMessage(param1);
}

void MapNpcsQuestStatusUpdateMessage::serializeAs_MapNpcsQuestStatusUpdateMessage(Writer *param1)
{
  param1->writeInt((int)this->mapId);
  param1->writeShort((short)this->npcsIdsWithQuest.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->npcsIdsWithQuest.size())
  {
    param1->writeInt((int)this->npcsIdsWithQuest[_loc2_]);
    _loc2_++;
  }
  param1->writeShort((short)this->questFlags.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->questFlags.size())
  {
    (this->questFlags[_loc3_]).serializeAs_GameRolePlayNpcQuestFlag(param1);
    _loc3_++;
  }
  param1->writeShort((short)this->npcsIdsWithoutQuest.size());
  uint _loc4_ = 0;
  while(_loc4_ < this->npcsIdsWithoutQuest.size())
  {
    param1->writeInt((int)this->npcsIdsWithoutQuest[_loc4_]);
    _loc4_++;
  }
}

void MapNpcsQuestStatusUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MapNpcsQuestStatusUpdateMessage(param1);
}

void MapNpcsQuestStatusUpdateMessage::deserializeAs_MapNpcsQuestStatusUpdateMessage(Reader *param1)
{
  auto _loc8_ = 0;
  GameRolePlayNpcQuestFlag _loc9_ ;
  auto _loc10_ = 0;
  this->mapId = param1->readInt();
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc8_ = param1->readInt();
    this->npcsIdsWithQuest.append(_loc8_);
    _loc3_++;
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc9_ = GameRolePlayNpcQuestFlag();
    _loc9_.deserialize(param1);
    this->questFlags.append(_loc9_);
    _loc5_++;
  }
  uint _loc6_ = param1->readUShort();
  uint _loc7_ = 0;
  while(_loc7_ < _loc6_)
  {
    _loc10_ = param1->readInt();
    this->npcsIdsWithoutQuest.append(_loc10_);
    _loc7_++;
  }
}

MapNpcsQuestStatusUpdateMessage::MapNpcsQuestStatusUpdateMessage()
{
  m_type = MessageEnum::MAPNPCSQUESTSTATUSUPDATEMESSAGE;
}

