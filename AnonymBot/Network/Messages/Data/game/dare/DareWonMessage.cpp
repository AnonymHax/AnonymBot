#include "DareWonMessage.h"

void DareWonMessage::serialize(Writer *param1)
{
  this->serializeAs_DareWonMessage(param1);
}

void DareWonMessage::serializeAs_DareWonMessage(Writer *param1)
{
  if(this->dareId < 0 || this->dareId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DareWonMessage -"<<"Forbidden value (" << this->dareId << ") on element dareId.";
  }
  else
  {
    param1->writeDouble(this->dareId);
    return;
  }
}

void DareWonMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DareWonMessage(param1);
}

void DareWonMessage::deserializeAs_DareWonMessage(Reader *param1)
{
  this->dareId = param1->readDouble();
  if(this->dareId < 0 || this->dareId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DareWonMessage -"<<"Forbidden value (" << this->dareId << ") on element of DareWonMessage.dareId.";
  }
  else
  {
    return;
  }
}

DareWonMessage::DareWonMessage()
{
  m_type = MessageEnum::DAREWONMESSAGE;
}

