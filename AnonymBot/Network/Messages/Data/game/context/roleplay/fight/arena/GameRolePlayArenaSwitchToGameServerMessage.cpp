#include "GameRolePlayArenaSwitchToGameServerMessage.h"

void GameRolePlayArenaSwitchToGameServerMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayArenaSwitchToGameServerMessage(param1);
}

void GameRolePlayArenaSwitchToGameServerMessage::serializeAs_GameRolePlayArenaSwitchToGameServerMessage(Writer *param1)
{
  param1->writeBool(this->validToken);
  param1->writeVarInt((int)this->ticket.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->ticket.size())
  {
    param1->writeByte(this->ticket[_loc2_]);
    _loc2_++;
  }
  param1->writeShort((short)this->homeServerId);
}

void GameRolePlayArenaSwitchToGameServerMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayArenaSwitchToGameServerMessage(param1);
}

void GameRolePlayArenaSwitchToGameServerMessage::deserializeAs_GameRolePlayArenaSwitchToGameServerMessage(Reader *param1)
{
  auto _loc4_ = 0;
  this->validToken = param1->readBool();
  uint _loc2_ = param1->readVarInt();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readByte();
    this->ticket.append(_loc4_);
    _loc3_++;
  }
  this->homeServerId = param1->readShort();
}

GameRolePlayArenaSwitchToGameServerMessage::GameRolePlayArenaSwitchToGameServerMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYARENASWITCHTOGAMESERVERMESSAGE;
}

