#include "ObjectUseMessage.h"

void ObjectUseMessage::serialize(Writer *param1)
{
  this->serializeAs_ObjectUseMessage(param1);
}

void ObjectUseMessage::serializeAs_ObjectUseMessage(Writer *param1)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectUseMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  else
  {
    param1->writeVarInt((int)this->objectUID);
    return;
  }
}

void ObjectUseMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectUseMessage(param1);
}

void ObjectUseMessage::deserializeAs_ObjectUseMessage(Reader *param1)
{
  this->objectUID = param1->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectUseMessage -"<<"Forbidden value (" << this->objectUID << ") on element of ObjectUseMessage.objectUID.";
  }
  else
  {
    return;
  }
}

ObjectUseMessage::ObjectUseMessage()
{
  m_type = MessageEnum::OBJECTUSEMESSAGE;
}

