#include "ObjectJobAddedMessage.h"

void ObjectJobAddedMessage::serialize(Writer *param1)
{
  this->serializeAs_ObjectJobAddedMessage(param1);
}

void ObjectJobAddedMessage::serializeAs_ObjectJobAddedMessage(Writer *param1)
{
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - ObjectJobAddedMessage -"<<"Forbidden value (" << this->jobId << ") on element jobId.";
  }
  else
  {
    param1->writeByte(this->jobId);
    return;
  }
}

void ObjectJobAddedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectJobAddedMessage(param1);
}

void ObjectJobAddedMessage::deserializeAs_ObjectJobAddedMessage(Reader *param1)
{
  this->jobId = param1->readByte();
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - ObjectJobAddedMessage -"<<"Forbidden value (" << this->jobId << ") on element of ObjectJobAddedMessage.jobId.";
  }
  else
  {
    return;
  }
}

ObjectJobAddedMessage::ObjectJobAddedMessage()
{
  m_type = MessageEnum::OBJECTJOBADDEDMESSAGE;
}

