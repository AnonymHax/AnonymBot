#include "ReloginTokenStatusMessage.h"

void ReloginTokenStatusMessage::serialize(Writer *param1)
{
  this->serializeAs_ReloginTokenStatusMessage(param1);
}

void ReloginTokenStatusMessage::serializeAs_ReloginTokenStatusMessage(Writer *param1)
{
  param1->writeBool(this->validToken);
  param1->writeVarInt((int)this->ticket.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->ticket.size())
  {
    param1->writeByte(this->ticket[_loc2_]);
    _loc2_++;
  }
}

void ReloginTokenStatusMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ReloginTokenStatusMessage(param1);
}

void ReloginTokenStatusMessage::deserializeAs_ReloginTokenStatusMessage(Reader *param1)
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
}

ReloginTokenStatusMessage::ReloginTokenStatusMessage()
{
  m_type = MessageEnum::RELOGINTOKENSTATUSMESSAGE;
}

