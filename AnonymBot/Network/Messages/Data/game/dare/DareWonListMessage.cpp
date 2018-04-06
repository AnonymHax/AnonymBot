#include "DareWonListMessage.h"

void DareWonListMessage::serialize(Writer *param1)
{
  this->serializeAs_DareWonListMessage(param1);
}

void DareWonListMessage::serializeAs_DareWonListMessage(Writer *param1)
{
  param1->writeShort((short)this->dareId.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->dareId.size())
  {
    if(this->dareId[_loc2_] < 0 || this->dareId[_loc2_] > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - DareWonListMessage -"<<"Forbidden value (" << this->dareId[_loc2_] << ") on element 1 (starting at 1) of dareId.";
    }
    else
    {
      param1->writeDouble(this->dareId[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void DareWonListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DareWonListMessage(param1);
}

void DareWonListMessage::deserializeAs_DareWonListMessage(Reader *param1)
{
  auto _loc4_ = NULL;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readDouble();
    if(_loc4_ < 0 || _loc4_ > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - DareWonListMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of dareId.";
    }
    else
    {
      this->dareId.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

DareWonListMessage::DareWonListMessage()
{
  m_type = MessageEnum::DAREWONLISTMESSAGE;
}

