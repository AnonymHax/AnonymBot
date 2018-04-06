#include "AcquaintanceServerListMessage.h"

void AcquaintanceServerListMessage::serialize(Writer *param1)
{
  this->serializeAs_AcquaintanceServerListMessage(param1);
}

void AcquaintanceServerListMessage::serializeAs_AcquaintanceServerListMessage(Writer *param1)
{
  param1->writeShort((short)this->servers.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->servers.size())
  {
    if(this->servers[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - AcquaintanceServerListMessage -"<<"Forbidden value (" << this->servers[_loc2_] << ") on element 1 (starting at 1) of servers.";
    }
    else
    {
      param1->writeVarShort((int)this->servers[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void AcquaintanceServerListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AcquaintanceServerListMessage(param1);
}

void AcquaintanceServerListMessage::deserializeAs_AcquaintanceServerListMessage(Reader *param1)
{
  uint _loc4_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readVarUhShort();
    if(_loc4_ < 0)
    {
      qDebug()<<"ERREUR - AcquaintanceServerListMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of servers.";
    }
    else
    {
      this->servers.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

AcquaintanceServerListMessage::AcquaintanceServerListMessage()
{
  m_type = MessageEnum::ACQUAINTANCESERVERLISTMESSAGE;
}

