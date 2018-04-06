#include "LeaveDialogMessage.h"

void LeaveDialogMessage::serialize(Writer *param1)
{
  this->serializeAs_LeaveDialogMessage(param1);
}

void LeaveDialogMessage::serializeAs_LeaveDialogMessage(Writer *param1)
{
  param1->writeByte(this->dialogType);
}

void LeaveDialogMessage::deserialize(Reader *param1)
{
  this->deserializeAs_LeaveDialogMessage(param1);
}

void LeaveDialogMessage::deserializeAs_LeaveDialogMessage(Reader *param1)
{
  this->dialogType = param1->readByte();
  if(this->dialogType < 0)
  {
    qDebug()<<"ERREUR - LeaveDialogMessage -"<<"Forbidden value (" << this->dialogType << ") on element of LeaveDialogMessage.dialogType.";
  }
  else
  {
    return;
  }
}

LeaveDialogMessage::LeaveDialogMessage()
{
  m_type = MessageEnum::LEAVEDIALOGMESSAGE;
}

