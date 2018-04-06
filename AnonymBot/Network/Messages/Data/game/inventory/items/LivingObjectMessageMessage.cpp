#include "LivingObjectMessageMessage.h"

void LivingObjectMessageMessage::serialize(Writer *param1)
{
  this->serializeAs_LivingObjectMessageMessage(param1);
}

void LivingObjectMessageMessage::serializeAs_LivingObjectMessageMessage(Writer *param1)
{
  if(this->msgId < 0)
  {
    qDebug()<<"ERREUR - LivingObjectMessageMessage -"<<"Forbidden value (" << this->msgId << ") on element msgId.";
  }
  else
  {
    param1->writeVarShort((int)this->msgId);
    if(this->timeStamp < 0)
    {
      qDebug()<<"ERREUR - LivingObjectMessageMessage -"<<"Forbidden value (" << this->timeStamp << ") on element timeStamp.";
    }
    else
    {
      param1->writeInt((int)this->timeStamp);
      param1->writeUTF(this->owner);
      if(this->objectGenericId < 0)
      {
        qDebug()<<"ERREUR - LivingObjectMessageMessage -"<<"Forbidden value (" << this->objectGenericId << ") on element objectGenericId.";
      }
      else
      {
        param1->writeVarShort((int)this->objectGenericId);
        return;
      }
    }
  }
}

void LivingObjectMessageMessage::deserialize(Reader *param1)
{
  this->deserializeAs_LivingObjectMessageMessage(param1);
}

void LivingObjectMessageMessage::deserializeAs_LivingObjectMessageMessage(Reader *param1)
{
  this->msgId = param1->readVarUhShort();
  if(this->msgId < 0)
  {
    qDebug()<<"ERREUR - LivingObjectMessageMessage -"<<"Forbidden value (" << this->msgId << ") on element of LivingObjectMessageMessage.msgId.";
  }
  else
  {
    this->timeStamp = param1->readInt();
    if(this->timeStamp < 0)
    {
      qDebug()<<"ERREUR - LivingObjectMessageMessage -"<<"Forbidden value (" << this->timeStamp << ") on element of LivingObjectMessageMessage.timeStamp.";
    }
    else
    {
      this->owner = param1->readUTF();
      this->objectGenericId = param1->readVarUhShort();
      if(this->objectGenericId < 0)
      {
        qDebug()<<"ERREUR - LivingObjectMessageMessage -"<<"Forbidden value (" << this->objectGenericId << ") on element of LivingObjectMessageMessage.objectGenericId.";
      }
      else
      {
        return;
      }
    }
  }
}

LivingObjectMessageMessage::LivingObjectMessageMessage()
{
  m_type = MessageEnum::LIVINGOBJECTMESSAGEMESSAGE;
}

