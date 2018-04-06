#include "ObjectFeedMessage.h"

void ObjectFeedMessage::serialize(Writer *param1)
{
  this->serializeAs_ObjectFeedMessage(param1);
}

void ObjectFeedMessage::serializeAs_ObjectFeedMessage(Writer *param1)
{
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectFeedMessage -"<<"Forbidden value (" << this->objectUID << ") on element objectUID.";
  }
  else
  {
    param1->writeVarInt((int)this->objectUID);
    if(this->foodUID < 0)
    {
      qDebug()<<"ERREUR - ObjectFeedMessage -"<<"Forbidden value (" << this->foodUID << ") on element foodUID.";
    }
    else
    {
      param1->writeVarInt((int)this->foodUID);
      if(this->foodQuantity < 0)
      {
        qDebug()<<"ERREUR - ObjectFeedMessage -"<<"Forbidden value (" << this->foodQuantity << ") on element foodQuantity.";
      }
      else
      {
        param1->writeVarInt((int)this->foodQuantity);
        return;
      }
    }
  }
}

void ObjectFeedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectFeedMessage(param1);
}

void ObjectFeedMessage::deserializeAs_ObjectFeedMessage(Reader *param1)
{
  this->objectUID = param1->readVarUhInt();
  if(this->objectUID < 0)
  {
    qDebug()<<"ERREUR - ObjectFeedMessage -"<<"Forbidden value (" << this->objectUID << ") on element of ObjectFeedMessage.objectUID.";
  }
  else
  {
    this->foodUID = param1->readVarUhInt();
    if(this->foodUID < 0)
    {
      qDebug()<<"ERREUR - ObjectFeedMessage -"<<"Forbidden value (" << this->foodUID << ") on element of ObjectFeedMessage.foodUID.";
    }
    else
    {
      this->foodQuantity = param1->readVarUhInt();
      if(this->foodQuantity < 0)
      {
        qDebug()<<"ERREUR - ObjectFeedMessage -"<<"Forbidden value (" << this->foodQuantity << ") on element of ObjectFeedMessage.foodQuantity.";
      }
      else
      {
        return;
      }
    }
  }
}

ObjectFeedMessage::ObjectFeedMessage()
{
  m_type = MessageEnum::OBJECTFEEDMESSAGE;
}

