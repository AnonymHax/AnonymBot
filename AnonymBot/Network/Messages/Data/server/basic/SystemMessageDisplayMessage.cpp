#include "SystemMessageDisplayMessage.h"

void SystemMessageDisplayMessage::serialize(Writer *param1)
{
  this->serializeAs_SystemMessageDisplayMessage(param1);
}

void SystemMessageDisplayMessage::serializeAs_SystemMessageDisplayMessage(Writer *param1)
{
  param1->writeBool(this->hangUp);
  if(this->msgId < 0)
  {
    qDebug()<<"ERREUR - SystemMessageDisplayMessage -"<<"Forbidden value (" << this->msgId << ") on element msgId.";
  }
  else
  {
    param1->writeVarShort((int)this->msgId);
    param1->writeShort((short)this->parameters.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->parameters.size())
    {
      param1->writeUTF(this->parameters[_loc2_]);
      _loc2_++;
    }
    return;
  }
}

void SystemMessageDisplayMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SystemMessageDisplayMessage(param1);
}

void SystemMessageDisplayMessage::deserializeAs_SystemMessageDisplayMessage(Reader *param1)
{
  QString _loc4_ ;
  this->hangUp = param1->readBool();
  this->msgId = param1->readVarUhShort();
  if(this->msgId < 0)
  {
    qDebug()<<"ERREUR - SystemMessageDisplayMessage -"<<"Forbidden value (" << this->msgId << ") on element of SystemMessageDisplayMessage.msgId.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = param1->readUTF();
      this->parameters.append(_loc4_);
      _loc3_++;
    }
    return;
  }
}

SystemMessageDisplayMessage::SystemMessageDisplayMessage()
{
  m_type = MessageEnum::SYSTEMMESSAGEDISPLAYMESSAGE;
}

