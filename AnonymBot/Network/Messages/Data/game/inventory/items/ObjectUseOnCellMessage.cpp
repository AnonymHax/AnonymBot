#include "ObjectUseOnCellMessage.h"

void ObjectUseOnCellMessage::serialize(Writer *param1)
{
  this->serializeAs_ObjectUseOnCellMessage(param1);
}

void ObjectUseOnCellMessage::serializeAs_ObjectUseOnCellMessage(Writer *param1)
{
  ObjectUseMessage::serializeAs_ObjectUseMessage(param1);
  if(this->cells < 0 || this->cells > 559)
  {
    qDebug()<<"ERREUR - ObjectUseOnCellMessage -"<<"Forbidden value (" << this->cells << ") on element cells.";
  }
  else
  {
    param1->writeVarShort((int)this->cells);
    return;
  }
}

void ObjectUseOnCellMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectUseOnCellMessage(param1);
}

void ObjectUseOnCellMessage::deserializeAs_ObjectUseOnCellMessage(Reader *param1)
{
  ObjectUseMessage::deserialize(param1);
  this->cells = param1->readVarUhShort();
  if(this->cells < 0 || this->cells > 559)
  {
    qDebug()<<"ERREUR - ObjectUseOnCellMessage -"<<"Forbidden value (" << this->cells << ") on element of ObjectUseOnCellMessage.cells.";
  }
  else
  {
    return;
  }
}

ObjectUseOnCellMessage::ObjectUseOnCellMessage()
{
  m_type = MessageEnum::OBJECTUSEONCELLMESSAGE;
}

