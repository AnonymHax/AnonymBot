#include "PauseDialogMessage.h"

void PauseDialogMessage::serialize(Writer *param1)
{
  this->serializeAs_PauseDialogMessage(param1);
}

void PauseDialogMessage::serializeAs_PauseDialogMessage(Writer *param1)
{
  param1->writeByte(this->dialogType);
}

void PauseDialogMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PauseDialogMessage(param1);
}

void PauseDialogMessage::deserializeAs_PauseDialogMessage(Reader *param1)
{
  this->dialogType = param1->readByte();
  if(this->dialogType < 0)
  {
    qDebug()<<"ERREUR - PauseDialogMessage -"<<"Forbidden value (" << this->dialogType << ") on element of PauseDialogMessage.dialogType.";
  }
  else
  {
    return;
  }
}

PauseDialogMessage::PauseDialogMessage()
{
  m_type = MessageEnum::PAUSEDIALOGMESSAGE;
}

