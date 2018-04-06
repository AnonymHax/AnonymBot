#include "DareCancelRequestMessage.h"

void DareCancelRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_DareCancelRequestMessage(param1);
}

void DareCancelRequestMessage::serializeAs_DareCancelRequestMessage(Writer *param1)
{
  if(this->dareId < 0 || this->dareId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DareCancelRequestMessage -"<<"Forbidden value (" << this->dareId << ") on element dareId.";
  }
  else
  {
    param1->writeDouble(this->dareId);
    return;
  }
}

void DareCancelRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DareCancelRequestMessage(param1);
}

void DareCancelRequestMessage::deserializeAs_DareCancelRequestMessage(Reader *param1)
{
  this->dareId = param1->readDouble();
  if(this->dareId < 0 || this->dareId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DareCancelRequestMessage -"<<"Forbidden value (" << this->dareId << ") on element of DareCancelRequestMessage.dareId.";
  }
  else
  {
    return;
  }
}

DareCancelRequestMessage::DareCancelRequestMessage()
{
  m_type = MessageEnum::DARECANCELREQUESTMESSAGE;
}

