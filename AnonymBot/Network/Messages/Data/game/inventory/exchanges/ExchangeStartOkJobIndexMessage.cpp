#include "ExchangeStartOkJobIndexMessage.h"

void ExchangeStartOkJobIndexMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeStartOkJobIndexMessage(param1);
}

void ExchangeStartOkJobIndexMessage::serializeAs_ExchangeStartOkJobIndexMessage(Writer *param1)
{
  param1->writeShort((short)this->jobs.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->jobs.size())
  {
    if(this->jobs[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - ExchangeStartOkJobIndexMessage -"<<"Forbidden value (" << this->jobs[_loc2_] << ") on element 1 (starting at 1) of jobs.";
    }
    else
    {
      param1->writeVarInt((int)this->jobs[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void ExchangeStartOkJobIndexMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeStartOkJobIndexMessage(param1);
}

void ExchangeStartOkJobIndexMessage::deserializeAs_ExchangeStartOkJobIndexMessage(Reader *param1)
{
  uint _loc4_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readVarUhInt();
    if(_loc4_ < 0)
    {
      qDebug()<<"ERREUR - ExchangeStartOkJobIndexMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of jobs.";
    }
    else
    {
      this->jobs.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

ExchangeStartOkJobIndexMessage::ExchangeStartOkJobIndexMessage()
{
  m_type = MessageEnum::EXCHANGESTARTOKJOBINDEXMESSAGE;
}

