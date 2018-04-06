#include "DareVersatileListMessage.h"

void DareVersatileListMessage::serialize(Writer *param1)
{
  this->serializeAs_DareVersatileListMessage(param1);
}

void DareVersatileListMessage::serializeAs_DareVersatileListMessage(Writer *param1)
{
  param1->writeShort((short)this->dares.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->dares.size())
  {
    (this->dares[_loc2_]).serializeAs_DareVersatileInformations(param1);
    _loc2_++;
  }
}

void DareVersatileListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DareVersatileListMessage(param1);
}

void DareVersatileListMessage::deserializeAs_DareVersatileListMessage(Reader *param1)
{
  DareVersatileInformations _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = DareVersatileInformations();
    _loc4_.deserialize(param1);
    this->dares.append(_loc4_);
    _loc3_++;
  }
}

DareVersatileListMessage::DareVersatileListMessage()
{
  m_type = MessageEnum::DAREVERSATILELISTMESSAGE;
}

