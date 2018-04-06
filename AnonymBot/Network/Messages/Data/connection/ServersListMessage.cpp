#include "ServersListMessage.h"

void ServersListMessage::serialize(Writer *param1)
{
  this->serializeAs_ServersListMessage(param1);
}

void ServersListMessage::serializeAs_ServersListMessage(Writer *param1)
{
  param1->writeShort((short)this->servers.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->servers.size())
  {
    (this->servers[_loc2_]).serializeAs_GameServerInformations(param1);
    _loc2_++;
  }
  if(this->alreadyConnectedToServerId < 0)
  {
    qDebug()<<"ERREUR - ServersListMessage -"<<"Forbidden value (" << this->alreadyConnectedToServerId << ") on element alreadyConnectedToServerId.";
  }
  else
  {
    param1->writeVarShort((int)this->alreadyConnectedToServerId);
    param1->writeBool(this->canCreateNewCharacter);
    return;
  }
}

void ServersListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ServersListMessage(param1);
}

void ServersListMessage::deserializeAs_ServersListMessage(Reader *param1)
{
  GameServerInformations _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = GameServerInformations();
    _loc4_.deserialize(param1);
    this->servers.append(_loc4_);
    _loc3_++;
  }
  this->alreadyConnectedToServerId = param1->readVarUhShort();
  if(this->alreadyConnectedToServerId < 0)
  {
    qDebug()<<"ERREUR - ServersListMessage -"<<"Forbidden value (" << this->alreadyConnectedToServerId << ") on element of ServersListMessage.alreadyConnectedToServerId.";
  }
  else
  {
    this->canCreateNewCharacter = param1->readBool();
    return;
  }
}

ServersListMessage::ServersListMessage()
{
  m_type = MessageEnum::SERVERSLISTMESSAGE;
}

