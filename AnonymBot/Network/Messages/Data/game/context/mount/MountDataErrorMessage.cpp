#include "MountDataErrorMessage.h"

void MountDataErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_MountDataErrorMessage(param1);
}

void MountDataErrorMessage::serializeAs_MountDataErrorMessage(Writer *param1)
{
  param1->writeByte(this->reason);
}

void MountDataErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MountDataErrorMessage(param1);
}

void MountDataErrorMessage::deserializeAs_MountDataErrorMessage(Reader *param1)
{
  this->reason = param1->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - MountDataErrorMessage -"<<"Forbidden value (" << this->reason << ") on element of MountDataErrorMessage.reason.";
  }
  else
  {
    return;
  }
}

MountDataErrorMessage::MountDataErrorMessage()
{
  m_type = MessageEnum::MOUNTDATAERRORMESSAGE;
}

