#include "LockableShowCodeDialogMessage.h"

void LockableShowCodeDialogMessage::serialize(Writer *param1)
{
  this->serializeAs_LockableShowCodeDialogMessage(param1);
}

void LockableShowCodeDialogMessage::serializeAs_LockableShowCodeDialogMessage(Writer *param1)
{
  param1->writeBool(this->changeOrUse);
  if(this->codeSize < 0)
  {
    qDebug()<<"ERREUR - LockableShowCodeDialogMessage -"<<"Forbidden value (" << this->codeSize << ") on element codeSize.";
  }
  else
  {
    param1->writeByte(this->codeSize);
    return;
  }
}

void LockableShowCodeDialogMessage::deserialize(Reader *param1)
{
  this->deserializeAs_LockableShowCodeDialogMessage(param1);
}

void LockableShowCodeDialogMessage::deserializeAs_LockableShowCodeDialogMessage(Reader *param1)
{
  this->changeOrUse = param1->readBool();
  this->codeSize = param1->readByte();
  if(this->codeSize < 0)
  {
    qDebug()<<"ERREUR - LockableShowCodeDialogMessage -"<<"Forbidden value (" << this->codeSize << ") on element of LockableShowCodeDialogMessage.codeSize.";
  }
  else
  {
    return;
  }
}

LockableShowCodeDialogMessage::LockableShowCodeDialogMessage()
{
  m_type = MessageEnum::LOCKABLESHOWCODEDIALOGMESSAGE;
}

