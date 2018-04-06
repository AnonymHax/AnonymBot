#include "HelloConnectMessage.h"

void HelloConnectMessage::serialize(Writer *param1)
{
  this->serializeAs_HelloConnectMessage(param1);
}

void HelloConnectMessage::serializeAs_HelloConnectMessage(Writer *param1)
{
  param1->writeUTF(this->salt);
  param1->writeVarInt((int)this->key.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->key.size())
  {
    param1->writeByte(this->key[_loc2_]);
    _loc2_++;
  }
}

void HelloConnectMessage::deserialize(Reader *param1)
{
  this->deserializeAs_HelloConnectMessage(param1);
}

void HelloConnectMessage::deserializeAs_HelloConnectMessage(Reader *param1)
{
  auto _loc4_ = 0;
  this->salt = param1->readUTF();
  uint _loc2_ = param1->readVarInt();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readByte();
    this->key.append(_loc4_);
    _loc3_++;
  }
}

HelloConnectMessage::HelloConnectMessage()
{
  m_type = MessageEnum::HELLOCONNECTMESSAGE;
}

