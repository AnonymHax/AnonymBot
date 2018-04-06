#include "ObjectDeletedMessage.h"

void ObjectDeletedMessage::serialize(Writer *param1)
{
  this->serializeAs_ObjectDeletedMessage(param1);
}

void ObjectDeletedMessage::serializeAs_ObjectDeletedMessage(Writer *param1)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectDeletedMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  else
  {
    param1->writeVarInt((int)this->objectUID);
    return;
  }
}

void ObjectDeletedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectDeletedMessage(param1);
}

void ObjectDeletedMessage::deserializeAs_ObjectDeletedMessage(Reader *param1)
{
  this->objectUID = param1->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectDeletedMessage -"<<"Forbidden value (" << this->objectUID << ") on element of ObjectDeletedMessage.objectUID.";
  }
  else
  {
    return;
  }
}

ObjectDeletedMessage::ObjectDeletedMessage()
{
  m_type = MessageEnum::OBJECTDELETEDMESSAGE;
}

