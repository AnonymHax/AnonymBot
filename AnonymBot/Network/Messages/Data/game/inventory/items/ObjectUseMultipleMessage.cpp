#include "ObjectUseMultipleMessage.h"

void ObjectUseMultipleMessage::serialize(Writer *param1)
{
  this->serializeAs_ObjectUseMultipleMessage(param1);
}

void ObjectUseMultipleMessage::serializeAs_ObjectUseMultipleMessage(Writer *param1)
{
  ObjectUseMessage::serializeAs_ObjectUseMessage(param1);
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectUseMultipleMessage -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
  }
  else
  {
    param1->writeVarInt((int)this->quantity);
    return;
  }
}

void ObjectUseMultipleMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectUseMultipleMessage(param1);
}

void ObjectUseMultipleMessage::deserializeAs_ObjectUseMultipleMessage(Reader *param1)
{
  ObjectUseMessage::deserialize(param1);
  this->quantity = param1->readVarUhInt();
  if(this->quantity < 0)
  {
    qDebug()<<"ERREUR - ObjectUseMultipleMessage -"<<"Forbidden value (" << this->quantity << ") on element of ObjectUseMultipleMessage.quantity.";
  }
  else
  {
    return;
  }
}

ObjectUseMultipleMessage::ObjectUseMultipleMessage()
{
  m_type = MessageEnum::OBJECTUSEMULTIPLEMESSAGE;
}

