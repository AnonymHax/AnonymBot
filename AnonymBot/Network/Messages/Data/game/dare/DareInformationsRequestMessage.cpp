#include "DareInformationsRequestMessage.h"

void DareInformationsRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_DareInformationsRequestMessage(param1);
}

void DareInformationsRequestMessage::serializeAs_DareInformationsRequestMessage(Writer *param1)
{
  if(this->dareId < 0 || this->dareId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DareInformationsRequestMessage -"<<"Forbidden value (" << this->dareId << ") on element dareId.";
  }
  else
  {
    param1->writeDouble(this->dareId);
    return;
  }
}

void DareInformationsRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DareInformationsRequestMessage(param1);
}

void DareInformationsRequestMessage::deserializeAs_DareInformationsRequestMessage(Reader *param1)
{
  this->dareId = param1->readDouble();
  if(this->dareId < 0 || this->dareId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DareInformationsRequestMessage -"<<"Forbidden value (" << this->dareId << ") on element of DareInformationsRequestMessage.dareId.";
  }
  else
  {
    return;
  }
}

DareInformationsRequestMessage::DareInformationsRequestMessage()
{
  m_type = MessageEnum::DAREINFORMATIONSREQUESTMESSAGE;
}

