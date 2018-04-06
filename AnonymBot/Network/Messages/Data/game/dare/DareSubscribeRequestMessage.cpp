#include "DareSubscribeRequestMessage.h"

void DareSubscribeRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_DareSubscribeRequestMessage(param1);
}

void DareSubscribeRequestMessage::serializeAs_DareSubscribeRequestMessage(Writer *param1)
{
  if(this->dareId < 0 || this->dareId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DareSubscribeRequestMessage -"<<"Forbidden value (" << this->dareId << ") on element dareId.";
  }
  else
  {
    param1->writeDouble(this->dareId);
    param1->writeBool(this->subscribe);
    return;
  }
}

void DareSubscribeRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DareSubscribeRequestMessage(param1);
}

void DareSubscribeRequestMessage::deserializeAs_DareSubscribeRequestMessage(Reader *param1)
{
  this->dareId = param1->readDouble();
  if(this->dareId < 0 || this->dareId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DareSubscribeRequestMessage -"<<"Forbidden value (" << this->dareId << ") on element of DareSubscribeRequestMessage.dareId.";
  }
  else
  {
    this->subscribe = param1->readBool();
    return;
  }
}

DareSubscribeRequestMessage::DareSubscribeRequestMessage()
{
  m_type = MessageEnum::DARESUBSCRIBEREQUESTMESSAGE;
}

