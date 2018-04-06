#include "LivingObjectChangeSkinRequestMessage.h"

void LivingObjectChangeSkinRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_LivingObjectChangeSkinRequestMessage(param1);
}

void LivingObjectChangeSkinRequestMessage::serializeAs_LivingObjectChangeSkinRequestMessage(Writer *param1)
{
  if(this->livingUID < 0)
  {
    qDebug()<<"ERREUR - LivingObjectChangeSkinRequestMessage -"<<"Forbidden value (" << this->livingUID << ") on element livingUID.";
  }
  else
  {
    param1->writeVarInt((int)this->livingUID);
    if(this->livingPosition < 0 || this->livingPosition > 255)
    {
      qDebug()<<"ERREUR - LivingObjectChangeSkinRequestMessage -"<<"Forbidden value (" << this->livingPosition << ") on element livingPosition.";
    }
    else
    {
      param1->writeByte(this->livingPosition);
      if(this->skinId < 0)
      {
        qDebug()<<"ERREUR - LivingObjectChangeSkinRequestMessage -"<<"Forbidden value (" << this->skinId << ") on element skinId.";
      }
      else
      {
        param1->writeVarInt((int)this->skinId);
        return;
      }
    }
  }
}

void LivingObjectChangeSkinRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_LivingObjectChangeSkinRequestMessage(param1);
}

void LivingObjectChangeSkinRequestMessage::deserializeAs_LivingObjectChangeSkinRequestMessage(Reader *param1)
{
  this->livingUID = param1->readVarUhInt();
  if(this->livingUID < 0)
  {
    qDebug()<<"ERREUR - LivingObjectChangeSkinRequestMessage -"<<"Forbidden value (" << this->livingUID << ") on element of LivingObjectChangeSkinRequestMessage.livingUID.";
  }
  else
  {
    this->livingPosition = param1->readUByte();
    if(this->livingPosition < 0 || this->livingPosition > 255)
    {
      qDebug()<<"ERREUR - LivingObjectChangeSkinRequestMessage -"<<"Forbidden value (" << this->livingPosition << ") on element of LivingObjectChangeSkinRequestMessage.livingPosition.";
    }
    else
    {
      this->skinId = param1->readVarUhInt();
      if(this->skinId < 0)
      {
        qDebug()<<"ERREUR - LivingObjectChangeSkinRequestMessage -"<<"Forbidden value (" << this->skinId << ") on element of LivingObjectChangeSkinRequestMessage.skinId.";
      }
      else
      {
        return;
      }
    }
  }
}

LivingObjectChangeSkinRequestMessage::LivingObjectChangeSkinRequestMessage()
{
  m_type = MessageEnum::LIVINGOBJECTCHANGESKINREQUESTMESSAGE;
}

