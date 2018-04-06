#include "DareListMessage.h"

void DareListMessage::serialize(Writer *param1)
{
  this->serializeAs_DareListMessage(param1);
}

void DareListMessage::serializeAs_DareListMessage(Writer *param1)
{
  param1->writeShort((short)this->dares.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->dares.size())
  {
    (this->dares[_loc2_]).serializeAs_DareInformations(param1);
    _loc2_++;
  }
}

void DareListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DareListMessage(param1);
}

void DareListMessage::deserializeAs_DareListMessage(Reader *param1)
{
  DareInformations _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = DareInformations();
    _loc4_.deserialize(param1);
    this->dares.append(_loc4_);
    _loc3_++;
  }
}

DareListMessage::DareListMessage()
{
  m_type = MessageEnum::DARELISTMESSAGE;
}

