#include "ObjectGroundAddedMessage.h"

void ObjectGroundAddedMessage::serialize(Writer *param1)
{
  this->serializeAs_ObjectGroundAddedMessage(param1);
}

void ObjectGroundAddedMessage::serializeAs_ObjectGroundAddedMessage(Writer *param1)
{
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - ObjectGroundAddedMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  else
  {
    param1->writeVarShort((int)this->cellId);
    if(this->objectGID < 0)
    {
      qDebug()<<"ERREUR - ObjectGroundAddedMessage -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
    }
    else
    {
      param1->writeVarShort((int)this->objectGID);
      return;
    }
  }
}

void ObjectGroundAddedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectGroundAddedMessage(param1);
}

void ObjectGroundAddedMessage::deserializeAs_ObjectGroundAddedMessage(Reader *param1)
{
  this->cellId = param1->readVarUhShort();
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - ObjectGroundAddedMessage -"<<"Forbidden value (" << this->cellId << ") on element of ObjectGroundAddedMessage.cellId.";
  }
  else
  {
    this->objectGID = param1->readVarUhShort();
    if(this->objectGID < 0)
    {
      qDebug()<<"ERREUR - ObjectGroundAddedMessage -"<<"Forbidden value (" << this->objectGID << ") on element of ObjectGroundAddedMessage.objectGID.";
    }
    else
    {
      return;
    }
  }
}

ObjectGroundAddedMessage::ObjectGroundAddedMessage()
{
  m_type = MessageEnum::OBJECTGROUNDADDEDMESSAGE;
}

