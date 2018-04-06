#include "LivingObjectMessageRequestMessage.h"

void LivingObjectMessageRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_LivingObjectMessageRequestMessage(param1);
}

void LivingObjectMessageRequestMessage::serializeAs_LivingObjectMessageRequestMessage(Writer *param1)
{
  if(this->msgId < 0)
  {
    qDebug()<<"ERREUR - LivingObjectMessageRequestMessage -"<<"Forbidden value (" << this->msgId << ") on element msgId.";
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
    if(this->livingObject < 0)
    {
      qDebug()<<"ERREUR - LivingObjectMessageRequestMessage -"<<"Forbidden value (" << this->livingObject << ") on element livingObject.";
    }
    else
    {
      param1->writeVarInt((int)this->livingObject);
      return;
    }
  }
}

void LivingObjectMessageRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_LivingObjectMessageRequestMessage(param1);
}

void LivingObjectMessageRequestMessage::deserializeAs_LivingObjectMessageRequestMessage(Reader *param1)
{
  QString _loc4_ ;
  this->msgId = param1->readVarUhShort();
  if(this->msgId < 0)
  {
    qDebug()<<"ERREUR - LivingObjectMessageRequestMessage -"<<"Forbidden value (" << this->msgId << ") on element of LivingObjectMessageRequestMessage.msgId.";
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
    this->livingObject = param1->readVarUhInt();
    if(this->livingObject < 0)
    {
      qDebug()<<"ERREUR - LivingObjectMessageRequestMessage -"<<"Forbidden value (" << this->livingObject << ") on element of LivingObjectMessageRequestMessage.livingObject.";
    }
    else
    {
      return;
    }
  }
}

LivingObjectMessageRequestMessage::LivingObjectMessageRequestMessage()
{
  m_type = MessageEnum::LIVINGOBJECTMESSAGEREQUESTMESSAGE;
}

