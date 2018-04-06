#include "RawDataMessage.h"

void RawDataMessage::serialize(Writer *param1)
{
  this->serializeAs_RawDataMessage(param1);
}

void RawDataMessage::serializeAs_RawDataMessage(Writer *param1)
{
  param1->writeVarInt((int)this->content.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->content.size())
  {
    param1->writeByte(this->content[_loc2_]);
    _loc2_++;
  }
}

void RawDataMessage::deserialize(Reader *param1)
{
  this->deserializeAs_RawDataMessage(param1);
}

void RawDataMessage::deserializeAs_RawDataMessage(Reader *param1)
{
  uint _loc2_ = param1->readVarInt();
  this->content = param1->readBytes();
}

RawDataMessage::RawDataMessage()
{
  m_type = MessageEnum::RAWDATAMESSAGE;
}

