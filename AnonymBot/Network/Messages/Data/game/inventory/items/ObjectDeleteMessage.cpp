#include "ObjectDeleteMessage.h"

void ObjectDeleteMessage::serialize(Writer *param1)
{
  this->serializeAs_ObjectDeleteMessage(param1);
}

void ObjectDeleteMessage::serializeAs_ObjectDeleteMessage(Writer *param1)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectDeleteMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  else
  {
    param1->writeVarInt((int)this->objectUID);
    if(this->quantity < 0)
    {
      qDebug()<<"ERREUR - ObjectDeleteMessage -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
    }
    else
    {
      param1->writeVarInt((int)this->quantity);
      return;
    }
  }
}

void ObjectDeleteMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectDeleteMessage(param1);
}

void ObjectDeleteMessage::deserializeAs_ObjectDeleteMessage(Reader *param1)
{
  this->objectUID = param1->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectDeleteMessage -"<<"Forbidden value (" << this->objectUID << ") on element of ObjectDeleteMessage.objectUID.";
  }
  else
  {
    this->quantity = param1->readVarUhInt();
    if(this->quantity < 0)
    {
      qDebug()<<"ERREUR - ObjectDeleteMessage -"<<"Forbidden value (" << this->quantity << ") on element of ObjectDeleteMessage.quantity.";
    }
    else
    {
      return;
    }
  }
}

ObjectDeleteMessage::ObjectDeleteMessage()
{
  m_type = MessageEnum::OBJECTDELETEMESSAGE;
}

