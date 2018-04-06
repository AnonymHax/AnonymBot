#include "LivingObjectDissociateMessage.h"

void LivingObjectDissociateMessage::serialize(Writer *param1)
{
  this->serializeAs_LivingObjectDissociateMessage(param1);
}

void LivingObjectDissociateMessage::serializeAs_LivingObjectDissociateMessage(Writer *param1)
{
  if(this->livingUID < 0)
  {
    qDebug()<<"ERREUR - LivingObjectDissociateMessage -"<<"Forbidden value (" << this->livingUID << ") on element livingUID.";
  }
  else
  {
    param1->writeVarInt((int)this->livingUID);
    if(this->livingPosition < 0 || this->livingPosition > 255)
    {
      qDebug()<<"ERREUR - LivingObjectDissociateMessage -"<<"Forbidden value (" << this->livingPosition << ") on element livingPosition.";
    }
    else
    {
      param1->writeByte(this->livingPosition);
      return;
    }
  }
}

void LivingObjectDissociateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_LivingObjectDissociateMessage(param1);
}

void LivingObjectDissociateMessage::deserializeAs_LivingObjectDissociateMessage(Reader *param1)
{
  this->livingUID = param1->readVarUhInt();
  if(this->livingUID < 0)
  {
    qDebug()<<"ERREUR - LivingObjectDissociateMessage -"<<"Forbidden value (" << this->livingUID << ") on element of LivingObjectDissociateMessage.livingUID.";
  }
  else
  {
    this->livingPosition = param1->readUByte();
    if(this->livingPosition < 0 || this->livingPosition > 255)
    {
      qDebug()<<"ERREUR - LivingObjectDissociateMessage -"<<"Forbidden value (" << this->livingPosition << ") on element of LivingObjectDissociateMessage.livingPosition.";
    }
    else
    {
      return;
    }
  }
}

LivingObjectDissociateMessage::LivingObjectDissociateMessage()
{
  m_type = MessageEnum::LIVINGOBJECTDISSOCIATEMESSAGE;
}

