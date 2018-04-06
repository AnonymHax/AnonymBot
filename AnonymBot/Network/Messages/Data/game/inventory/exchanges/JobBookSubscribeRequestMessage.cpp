#include "JobBookSubscribeRequestMessage.h"

void JobBookSubscribeRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_JobBookSubscribeRequestMessage(param1);
}

void JobBookSubscribeRequestMessage::serializeAs_JobBookSubscribeRequestMessage(Writer *param1)
{
  param1->writeShort((short)this->jobIds.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->jobIds.size())
  {
    if(this->jobIds[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - JobBookSubscribeRequestMessage -"<<"Forbidden value (" << this->jobIds[_loc2_] << ") on element 1 (starting at 1) of jobIds.";
    }
    else
    {
      param1->writeByte(this->jobIds[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void JobBookSubscribeRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_JobBookSubscribeRequestMessage(param1);
}

void JobBookSubscribeRequestMessage::deserializeAs_JobBookSubscribeRequestMessage(Reader *param1)
{
  uint _loc4_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readByte();
    if(_loc4_ < 0)
    {
      qDebug()<<"ERREUR - JobBookSubscribeRequestMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of jobIds.";
    }
    else
    {
      this->jobIds.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

JobBookSubscribeRequestMessage::JobBookSubscribeRequestMessage()
{
  m_type = MessageEnum::JOBBOOKSUBSCRIBEREQUESTMESSAGE;
}

