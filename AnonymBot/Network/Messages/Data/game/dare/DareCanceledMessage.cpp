#include "DareCanceledMessage.h"

void DareCanceledMessage::serialize(Writer *param1)
{
  this->serializeAs_DareCanceledMessage(param1);
}

void DareCanceledMessage::serializeAs_DareCanceledMessage(Writer *param1)
{
  if(this->dareId < 0 || this->dareId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DareCanceledMessage -"<<"Forbidden value (" << this->dareId << ") on element dareId.";
  }
  else
  {
    param1->writeDouble(this->dareId);
    return;
  }
}

void DareCanceledMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DareCanceledMessage(param1);
}

void DareCanceledMessage::deserializeAs_DareCanceledMessage(Reader *param1)
{
  this->dareId = param1->readDouble();
  if(this->dareId < 0 || this->dareId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DareCanceledMessage -"<<"Forbidden value (" << this->dareId << ") on element of DareCanceledMessage.dareId.";
  }
  else
  {
    return;
  }
}

DareCanceledMessage::DareCanceledMessage()
{
  m_type = MessageEnum::DARECANCELEDMESSAGE;
}

