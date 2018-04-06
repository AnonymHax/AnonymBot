#include "ObjectDropMessage.h"

void ObjectDropMessage::serialize(Writer *param1)
{
  this->serializeAs_ObjectDropMessage(param1);
}

void ObjectDropMessage::serializeAs_ObjectDropMessage(Writer *param1)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectDropMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  else
  {
    param1->writeVarInt((int)this->objectUID);
    if(this->quantity < 0)
    {
      qDebug()<<"ERREUR - ObjectDropMessage -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
    }
    else
    {
      param1->writeVarInt((int)this->quantity);
      return;
    }
  }
}

void ObjectDropMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectDropMessage(param1);
}

void ObjectDropMessage::deserializeAs_ObjectDropMessage(Reader *param1)
{
  this->objectUID = param1->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectDropMessage -"<<"Forbidden value (" << this->objectUID << ") on element of ObjectDropMessage.objectUID.";
  }
  else
  {
    this->quantity = param1->readVarUhInt();
    if(this->quantity < 0)
    {
      qDebug()<<"ERREUR - ObjectDropMessage -"<<"Forbidden value (" << this->quantity << ") on element of ObjectDropMessage.quantity.";
    }
    else
    {
      return;
    }
  }
}

ObjectDropMessage::ObjectDropMessage()
{
  m_type = MessageEnum::OBJECTDROPMESSAGE;
}

