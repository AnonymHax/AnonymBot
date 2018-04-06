#include "ObjectMovementMessage.h"

void ObjectMovementMessage::serialize(Writer *param1)
{
  this->serializeAs_ObjectMovementMessage(param1);
}

void ObjectMovementMessage::serializeAs_ObjectMovementMessage(Writer *param1)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectMovementMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  else
  {
    param1->writeVarInt((int)this->objectUID);
    param1->writeByte(this->position);
    return;
  }
}

void ObjectMovementMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectMovementMessage(param1);
}

void ObjectMovementMessage::deserializeAs_ObjectMovementMessage(Reader *param1)
{
  this->objectUID = param1->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectMovementMessage -"<<"Forbidden value (" << this->objectUID << ") on element of ObjectMovementMessage.objectUID.";
  }
  else
  {
    this->position = param1->readUByte();
    if(this->position < 0 || this->position > 255)
    {
      qDebug()<<"ERREUR - ObjectMovementMessage -"<<"Forbidden value (" << this->position << ") on element of ObjectMovementMessage.position.";
    }
    else
    {
      return;
    }
  }
}

ObjectMovementMessage::ObjectMovementMessage()
{
  m_type = MessageEnum::OBJECTMOVEMENTMESSAGE;
}

