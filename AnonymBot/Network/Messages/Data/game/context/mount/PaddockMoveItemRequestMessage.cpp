#include "PaddockMoveItemRequestMessage.h"

void PaddockMoveItemRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_PaddockMoveItemRequestMessage(param1);
}

void PaddockMoveItemRequestMessage::serializeAs_PaddockMoveItemRequestMessage(Writer *param1)
{
  if(this->oldCellId < 0 || this->oldCellId > 559)
  {
    qDebug()<<"ERREUR - PaddockMoveItemRequestMessage -"<<"Forbidden value (" << this->oldCellId << ") on element oldCellId.";
  }
  else
  {
    param1->writeVarShort((int)this->oldCellId);
    if(this->newCellId < 0 || this->newCellId > 559)
    {
      qDebug()<<"ERREUR - PaddockMoveItemRequestMessage -"<<"Forbidden value (" << this->newCellId << ") on element newCellId.";
    }
    else
    {
      param1->writeVarShort((int)this->newCellId);
      return;
    }
  }
}

void PaddockMoveItemRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PaddockMoveItemRequestMessage(param1);
}

void PaddockMoveItemRequestMessage::deserializeAs_PaddockMoveItemRequestMessage(Reader *param1)
{
  this->oldCellId = param1->readVarUhShort();
  if(this->oldCellId < 0 || this->oldCellId > 559)
  {
    qDebug()<<"ERREUR - PaddockMoveItemRequestMessage -"<<"Forbidden value (" << this->oldCellId << ") on element of PaddockMoveItemRequestMessage.oldCellId.";
  }
  else
  {
    this->newCellId = param1->readVarUhShort();
    if(this->newCellId < 0 || this->newCellId > 559)
    {
      qDebug()<<"ERREUR - PaddockMoveItemRequestMessage -"<<"Forbidden value (" << this->newCellId << ") on element of PaddockMoveItemRequestMessage.newCellId.";
    }
    else
    {
      return;
    }
  }
}

PaddockMoveItemRequestMessage::PaddockMoveItemRequestMessage()
{
  m_type = MessageEnum::PADDOCKMOVEITEMREQUESTMESSAGE;
}

