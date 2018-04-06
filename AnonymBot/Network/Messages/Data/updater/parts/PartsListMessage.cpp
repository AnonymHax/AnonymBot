#include "PartsListMessage.h"

void PartsListMessage::serialize(Writer *param1)
{
  this->serializeAs_PartsListMessage(param1);
}

void PartsListMessage::serializeAs_PartsListMessage(Writer *param1)
{
  param1->writeShort((short)this->parts.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->parts.size())
  {
    (this->parts[_loc2_]).serializeAs_ContentPart(param1);
    _loc2_++;
  }
}

void PartsListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PartsListMessage(param1);
}

void PartsListMessage::deserializeAs_PartsListMessage(Reader *param1)
{
  ContentPart _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = ContentPart();
    _loc4_.deserialize(param1);
    this->parts.append(_loc4_);
    _loc3_++;
  }
}

PartsListMessage::PartsListMessage()
{
  m_type = MessageEnum::PARTSLISTMESSAGE;
}

