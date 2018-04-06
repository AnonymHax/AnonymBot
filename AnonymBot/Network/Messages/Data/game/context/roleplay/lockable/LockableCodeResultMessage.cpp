#include "LockableCodeResultMessage.h"

void LockableCodeResultMessage::serialize(Writer *param1)
{
  this->serializeAs_LockableCodeResultMessage(param1);
}

void LockableCodeResultMessage::serializeAs_LockableCodeResultMessage(Writer *param1)
{
  param1->writeByte(this->result);
}

void LockableCodeResultMessage::deserialize(Reader *param1)
{
  this->deserializeAs_LockableCodeResultMessage(param1);
}

void LockableCodeResultMessage::deserializeAs_LockableCodeResultMessage(Reader *param1)
{
  this->result = param1->readByte();
  if(this->result < 0)
  {
    qDebug()<<"ERREUR - LockableCodeResultMessage -"<<"Forbidden value (" << this->result << ") on element of LockableCodeResultMessage.result.";
  }
  else
  {
    return;
  }
}

LockableCodeResultMessage::LockableCodeResultMessage()
{
  m_type = MessageEnum::LOCKABLECODERESULTMESSAGE;
}

