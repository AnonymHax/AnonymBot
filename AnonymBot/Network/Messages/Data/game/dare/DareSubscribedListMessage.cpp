#include "DareSubscribedListMessage.h"

void DareSubscribedListMessage::serialize(Writer *param1)
{
  this->serializeAs_DareSubscribedListMessage(param1);
}

void DareSubscribedListMessage::serializeAs_DareSubscribedListMessage(Writer *param1)
{
  param1->writeShort((short)this->daresFixedInfos.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->daresFixedInfos.size())
  {
    (this->daresFixedInfos[_loc2_]).serializeAs_DareInformations(param1);
    _loc2_++;
  }
  param1->writeShort((short)this->daresVersatilesInfos.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->daresVersatilesInfos.size())
  {
    (this->daresVersatilesInfos[_loc3_]).serializeAs_DareVersatileInformations(param1);
    _loc3_++;
  }
}

void DareSubscribedListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DareSubscribedListMessage(param1);
}

void DareSubscribedListMessage::deserializeAs_DareSubscribedListMessage(Reader *param1)
{
  DareInformations _loc6_ ;
  DareVersatileInformations _loc7_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc6_ = DareInformations();
    _loc6_.deserialize(param1);
    this->daresFixedInfos.append(_loc6_);
    _loc3_++;
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc7_ = DareVersatileInformations();
    _loc7_.deserialize(param1);
    this->daresVersatilesInfos.append(_loc7_);
    _loc5_++;
  }
}

DareSubscribedListMessage::DareSubscribedListMessage()
{
  m_type = MessageEnum::DARESUBSCRIBEDLISTMESSAGE;
}

