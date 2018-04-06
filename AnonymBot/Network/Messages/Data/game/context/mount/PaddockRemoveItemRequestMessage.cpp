#include "PaddockRemoveItemRequestMessage.h"

void PaddockRemoveItemRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_PaddockRemoveItemRequestMessage(param1);
}

void PaddockRemoveItemRequestMessage::serializeAs_PaddockRemoveItemRequestMessage(Writer *param1)
{
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - PaddockRemoveItemRequestMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  else
  {
    param1->writeVarShort((int)this->cellId);
    return;
  }
}

void PaddockRemoveItemRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PaddockRemoveItemRequestMessage(param1);
}

void PaddockRemoveItemRequestMessage::deserializeAs_PaddockRemoveItemRequestMessage(Reader *param1)
{
  this->cellId = param1->readVarUhShort();
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - PaddockRemoveItemRequestMessage -"<<"Forbidden value (" << this->cellId << ") on element of PaddockRemoveItemRequestMessage.cellId.";
  }
  else
  {
    return;
  }
}

PaddockRemoveItemRequestMessage::PaddockRemoveItemRequestMessage()
{
  m_type = MessageEnum::PADDOCKREMOVEITEMREQUESTMESSAGE;
}

