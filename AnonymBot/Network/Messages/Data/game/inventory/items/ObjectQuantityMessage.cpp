#include "ObjectQuantityMessage.h"

void ObjectQuantityMessage::serialize(Writer *param1)
{
  this->serializeAs_ObjectQuantityMessage(param1);
}

void ObjectQuantityMessage::serializeAs_ObjectQuantityMessage(Writer *param1)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectQuantityMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  else
  {
    param1->writeVarInt((int)this->objectUID);
    if(this->quantity < 0)
    {
      qDebug()<<"ERREUR - ObjectQuantityMessage -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
    }
    else
    {
      param1->writeVarInt((int)this->quantity);
      return;
    }
  }
}

void ObjectQuantityMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectQuantityMessage(param1);
}

void ObjectQuantityMessage::deserializeAs_ObjectQuantityMessage(Reader *param1)
{
  this->objectUID = param1->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectQuantityMessage -"<<"Forbidden value (" << this->objectUID << ") on element of ObjectQuantityMessage.objectUID.";
  }
  else
  {
    this->quantity = param1->readVarUhInt();
    if(this->quantity < 0)
    {
      qDebug()<<"ERREUR - ObjectQuantityMessage -"<<"Forbidden value (" << this->quantity << ") on element of ObjectQuantityMessage.quantity.";
    }
    else
    {
      return;
    }
  }
}

ObjectQuantityMessage::ObjectQuantityMessage()
{
  m_type = MessageEnum::OBJECTQUANTITYMESSAGE;
}

