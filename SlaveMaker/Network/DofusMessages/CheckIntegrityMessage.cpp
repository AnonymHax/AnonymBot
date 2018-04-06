#include "CheckIntegrityMessage.h"

void CheckIntegrityMessage::serialize(Writer *param1)
{
  this->serializeAs_CheckIntegrityMessage(param1);
}

void CheckIntegrityMessage::serializeAs_CheckIntegrityMessage(Writer *param1)
{
  param1->writeShort((short)this->data.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->data.size())
  {
    param1->writeByte(this->data[_loc2_]);
    _loc2_++;
  }
}

void CheckIntegrityMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CheckIntegrityMessage(param1);
}

void CheckIntegrityMessage::deserializeAs_CheckIntegrityMessage(Reader *param1)
{
  auto _loc4_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readByte();
    this->data.append(_loc4_);
    _loc3_++;
  }
}

CheckIntegrityMessage::CheckIntegrityMessage()
{
  m_type = DofusMessageEnum::CHECKINTEGRITYMESSAGE;
}

