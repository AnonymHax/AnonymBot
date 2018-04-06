#include "GameRolePlayArenaSwitchToFightServerMessage.h"

void GameRolePlayArenaSwitchToFightServerMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayArenaSwitchToFightServerMessage(param1);
}

void GameRolePlayArenaSwitchToFightServerMessage::serializeAs_GameRolePlayArenaSwitchToFightServerMessage(Writer *param1)
{
  param1->writeUTF(this->address);
  if(this->port < 0 || this->port > 65535)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaSwitchToFightServerMessage -"<<"Forbidden value (" << this->port << ") on element port.";
  }
  else
  {
    param1->writeShort((short)this->port);
    param1->writeVarInt((int)this->ticket.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->ticket.size())
    {
      param1->writeByte(this->ticket[_loc2_]);
      _loc2_++;
    }
    return;
  }
}

void GameRolePlayArenaSwitchToFightServerMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayArenaSwitchToFightServerMessage(param1);
}

void GameRolePlayArenaSwitchToFightServerMessage::deserializeAs_GameRolePlayArenaSwitchToFightServerMessage(Reader *param1)
{
  auto _loc4_ = 0;
  this->address = param1->readUTF();
  this->port = param1->readUShort();
  if(this->port < 0 || this->port > 65535)
  {
    qDebug()<<"ERREUR - GameRolePlayArenaSwitchToFightServerMessage -"<<"Forbidden value (" << this->port << ") on element of GameRolePlayArenaSwitchToFightServerMessage.port.";
  }
  else
  {
    uint _loc2_ = param1->readVarInt();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = param1->readByte();
      this->ticket.append(_loc4_);
      _loc3_++;
    }
    return;
  }
}

GameRolePlayArenaSwitchToFightServerMessage::GameRolePlayArenaSwitchToFightServerMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYARENASWITCHTOFIGHTSERVERMESSAGE;
  m_needsHash = true;
}

