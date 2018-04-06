#include "ObtainedItemMessage.h"

void ObtainedItemMessage::serialize(Writer *param1)
{
  this->serializeAs_ObtainedItemMessage(param1);
}

void ObtainedItemMessage::serializeAs_ObtainedItemMessage(Writer *param1)
{
  if(this->genericId < 0)
  {
    qDebug()<<"ERREUR - ObtainedItemMessage -"<<"Forbidden value (" << this->genericId << ") on element genericId.";
  }
  else
  {
    param1->writeVarShort((int)this->genericId);
    if(this->baseQuantity < 0)
    {
      qDebug()<<"ERREUR - ObtainedItemMessage -"<<"Forbidden value (" << this->baseQuantity << ") on element baseQuantity.";
    }
    else
    {
      param1->writeVarInt((int)this->baseQuantity);
      return;
    }
  }
}

void ObtainedItemMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObtainedItemMessage(param1);
}

void ObtainedItemMessage::deserializeAs_ObtainedItemMessage(Reader *param1)
{
  this->genericId = param1->readVarUhShort();
  if(this->genericId < 0)
  {
    qDebug()<<"ERREUR - ObtainedItemMessage -"<<"Forbidden value (" << this->genericId << ") on element of ObtainedItemMessage.genericId.";
  }
  else
  {
    this->baseQuantity = param1->readVarUhInt();
    if(this->baseQuantity < 0)
    {
      qDebug()<<"ERREUR - ObtainedItemMessage -"<<"Forbidden value (" << this->baseQuantity << ") on element of ObtainedItemMessage.baseQuantity.";
    }
    else
    {
      return;
    }
  }
}

ObtainedItemMessage::ObtainedItemMessage()
{
  m_type = MessageEnum::OBTAINEDITEMMESSAGE;
}

