#include "DebugInClientMessage.h"

void DebugInClientMessage::serialize(Writer *param1)
{
  this->serializeAs_DebugInClientMessage(param1);
}

void DebugInClientMessage::serializeAs_DebugInClientMessage(Writer *param1)
{
  param1->writeByte(this->level);
  param1->writeUTF(this->message);
}

void DebugInClientMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DebugInClientMessage(param1);
}

void DebugInClientMessage::deserializeAs_DebugInClientMessage(Reader *param1)
{
  this->level = param1->readByte();
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - DebugInClientMessage -"<<"Forbidden value (" << this->level << ") on element of DebugInClientMessage.level.";
  }
  else
  {
    this->message = param1->readUTF();
    return;
  }
}

DebugInClientMessage::DebugInClientMessage()
{
  m_type = MessageEnum::DEBUGINCLIENTMESSAGE;
}

