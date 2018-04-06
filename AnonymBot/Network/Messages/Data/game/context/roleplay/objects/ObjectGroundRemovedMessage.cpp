#include "ObjectGroundRemovedMessage.h"

void ObjectGroundRemovedMessage::serialize(Writer *param1)
{
  this->serializeAs_ObjectGroundRemovedMessage(param1);
}

void ObjectGroundRemovedMessage::serializeAs_ObjectGroundRemovedMessage(Writer *param1)
{
  if(this->cell < 0 || this->cell > 559)
  {
    qDebug()<<"ERREUR - ObjectGroundRemovedMessage -"<<"Forbidden value (" << this->cell << ") on element cell.";
  }
  else
  {
    param1->writeVarShort((int)this->cell);
    return;
  }
}

void ObjectGroundRemovedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectGroundRemovedMessage(param1);
}

void ObjectGroundRemovedMessage::deserializeAs_ObjectGroundRemovedMessage(Reader *param1)
{
  this->cell = param1->readVarUhShort();
  if(this->cell < 0 || this->cell > 559)
  {
    qDebug()<<"ERREUR - ObjectGroundRemovedMessage -"<<"Forbidden value (" << this->cell << ") on element of ObjectGroundRemovedMessage.cell.";
  }
  else
  {
    return;
  }
}

ObjectGroundRemovedMessage::ObjectGroundRemovedMessage()
{
  m_type = MessageEnum::OBJECTGROUNDREMOVEDMESSAGE;
}

