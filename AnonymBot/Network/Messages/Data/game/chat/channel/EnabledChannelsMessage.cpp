#include "EnabledChannelsMessage.h"

void EnabledChannelsMessage::serialize(Writer *param1)
{
  this->serializeAs_EnabledChannelsMessage(param1);
}

void EnabledChannelsMessage::serializeAs_EnabledChannelsMessage(Writer *param1)
{
  param1->writeShort((short)this->channels.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->channels.size())
  {
    param1->writeByte(this->channels[_loc2_]);
    _loc2_++;
  }
  param1->writeShort((short)this->disallowed.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->disallowed.size())
  {
    param1->writeByte(this->disallowed[_loc3_]);
    _loc3_++;
  }
}

void EnabledChannelsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_EnabledChannelsMessage(param1);
}

void EnabledChannelsMessage::deserializeAs_EnabledChannelsMessage(Reader *param1)
{
  uint _loc6_ = 0;
  uint _loc7_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc6_ = param1->readByte();
    if(_loc6_ < 0)
    {
      qDebug()<<"ERREUR - EnabledChannelsMessage -"<<"Forbidden value (" << _loc6_ << ") on elements of channels.";
    }
    else
    {
      this->channels.append(_loc6_);
      _loc3_++;
      continue;
    }
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc7_ = param1->readByte();
    if(_loc7_ < 0)
    {
      qDebug()<<"ERREUR - EnabledChannelsMessage -"<<"Forbidden value (" << _loc7_ << ") on elements of disallowed.";
    }
    else
    {
      this->disallowed.append(_loc7_);
      _loc5_++;
      continue;
    }
  }
}

EnabledChannelsMessage::EnabledChannelsMessage()
{
  m_type = MessageEnum::ENABLEDCHANNELSMESSAGE;
}

