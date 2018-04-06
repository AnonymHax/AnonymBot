#include "ObjectSetPositionMessage.h"

void ObjectSetPositionMessage::serialize(Writer *param1)
{
  this->serializeAs_ObjectSetPositionMessage(param1);
}

void ObjectSetPositionMessage::serializeAs_ObjectSetPositionMessage(Writer *param1)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectSetPositionMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  else
  {
    param1->writeVarInt((int)this->objectUID);
    param1->writeByte(this->position);
    if(this->quantity < 0)
    {
      qDebug()<<"ERREUR - ObjectSetPositionMessage -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
    }
    else
    {
      param1->writeVarInt((int)this->quantity);
      return;
    }
  }
}

void ObjectSetPositionMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectSetPositionMessage(param1);
}

void ObjectSetPositionMessage::deserializeAs_ObjectSetPositionMessage(Reader *param1)
{
  this->objectUID = param1->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectSetPositionMessage -"<<"Forbidden value (" << this->objectUID << ") on element of ObjectSetPositionMessage.objectUID.";
  }
  else
  {
    this->position = param1->readUByte();
    if(this->position < 0 || this->position > 255)
    {
      qDebug()<<"ERREUR - ObjectSetPositionMessage -"<<"Forbidden value (" << this->position << ") on element of ObjectSetPositionMessage.position.";
    }
    else
    {
      this->quantity = param1->readVarUhInt();
      if(this->quantity < 0)
      {
        qDebug()<<"ERREUR - ObjectSetPositionMessage -"<<"Forbidden value (" << this->quantity << ") on element of ObjectSetPositionMessage.quantity.";
      }
      else
      {
        return;
      }
    }
  }
}

ObjectSetPositionMessage::ObjectSetPositionMessage()
{
  m_type = MessageEnum::OBJECTSETPOSITIONMESSAGE;
}

