#include "AccessoryPreviewRequestMessage.h"

void AccessoryPreviewRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_AccessoryPreviewRequestMessage(param1);
}

void AccessoryPreviewRequestMessage::serializeAs_AccessoryPreviewRequestMessage(Writer *param1)
{
  param1->writeShort((short)this->genericId.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->genericId.size())
  {
    if(this->genericId[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - AccessoryPreviewRequestMessage -"<<"Forbidden value (" << this->genericId[_loc2_] << ") on element 1 (starting at 1) of genericId.";
    }
    else
    {
      param1->writeVarShort((int)this->genericId[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void AccessoryPreviewRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AccessoryPreviewRequestMessage(param1);
}

void AccessoryPreviewRequestMessage::deserializeAs_AccessoryPreviewRequestMessage(Reader *param1)
{
  uint _loc4_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readVarUhShort();
    if(_loc4_ < 0)
    {
      qDebug()<<"ERREUR - AccessoryPreviewRequestMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of genericId.";
    }
    else
    {
      this->genericId.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

AccessoryPreviewRequestMessage::AccessoryPreviewRequestMessage()
{
  m_type = MessageEnum::ACCESSORYPREVIEWREQUESTMESSAGE;
}

