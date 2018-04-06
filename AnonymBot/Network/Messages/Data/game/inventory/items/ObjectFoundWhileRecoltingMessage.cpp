#include "ObjectFoundWhileRecoltingMessage.h"

void ObjectFoundWhileRecoltingMessage::serialize(Writer *param1)
{
  this->serializeAs_ObjectFoundWhileRecoltingMessage(param1);
}

void ObjectFoundWhileRecoltingMessage::serializeAs_ObjectFoundWhileRecoltingMessage(Writer *param1)
{
  if(this->genericId < 0)
  {
    qDebug()<<"ERREUR - ObjectFoundWhileRecoltingMessage -"<<"Forbidden value (" << this->genericId << ") on element genericId.";
  }
  else
  {
    param1->writeVarShort((int)this->genericId);
    if(this->quantity < 0)
    {
      qDebug()<<"ERREUR - ObjectFoundWhileRecoltingMessage -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
    }
    else
    {
      param1->writeVarInt((int)this->quantity);
      if(this->resourceGenericId < 0)
      {
        qDebug()<<"ERREUR - ObjectFoundWhileRecoltingMessage -"<<"Forbidden value (" << this->resourceGenericId << ") on element resourceGenericId.";
      }
      else
      {
        param1->writeVarInt((int)this->resourceGenericId);
        return;
      }
    }
  }
}

void ObjectFoundWhileRecoltingMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectFoundWhileRecoltingMessage(param1);
}

void ObjectFoundWhileRecoltingMessage::deserializeAs_ObjectFoundWhileRecoltingMessage(Reader *param1)
{
  this->genericId = param1->readVarUhShort();
  if(this->genericId < 0)
  {
    qDebug()<<"ERREUR - ObjectFoundWhileRecoltingMessage -"<<"Forbidden value (" << this->genericId << ") on element of ObjectFoundWhileRecoltingMessage.genericId.";
  }
  else
  {
    this->quantity = param1->readVarUhInt();
    if(this->quantity < 0)
    {
      qDebug()<<"ERREUR - ObjectFoundWhileRecoltingMessage -"<<"Forbidden value (" << this->quantity << ") on element of ObjectFoundWhileRecoltingMessage.quantity.";
    }
    else
    {
      this->resourceGenericId = param1->readVarUhInt();
      if(this->resourceGenericId < 0)
      {
        qDebug()<<"ERREUR - ObjectFoundWhileRecoltingMessage -"<<"Forbidden value (" << this->resourceGenericId << ") on element of ObjectFoundWhileRecoltingMessage.resourceGenericId.";
      }
      else
      {
        return;
      }
    }
  }
}

ObjectFoundWhileRecoltingMessage::ObjectFoundWhileRecoltingMessage()
{
  m_type = MessageEnum::OBJECTFOUNDWHILERECOLTINGMESSAGE;
}

