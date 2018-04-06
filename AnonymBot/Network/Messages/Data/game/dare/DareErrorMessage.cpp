#include "DareErrorMessage.h"

void DareErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_DareErrorMessage(param1);
}

void DareErrorMessage::serializeAs_DareErrorMessage(Writer *param1)
{
  param1->writeByte(this->error);
}

void DareErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DareErrorMessage(param1);
}

void DareErrorMessage::deserializeAs_DareErrorMessage(Reader *param1)
{
  this->error = param1->readByte();
  if(this->error < 0)
  {
    qDebug()<<"ERREUR - DareErrorMessage -"<<"Forbidden value (" << this->error << ") on element of DareErrorMessage.error.";
  }
  else
  {
    return;
  }
}

DareErrorMessage::DareErrorMessage()
{
  m_type = MessageEnum::DAREERRORMESSAGE;
}

