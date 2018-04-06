#include "CheckFileMessage.h"

void CheckFileMessage::serialize(Writer *param1)
{
  this->serializeAs_CheckFileMessage(param1);
}

void CheckFileMessage::serializeAs_CheckFileMessage(Writer *param1)
{
  param1->writeUTF(this->filenameHash);
  param1->writeByte(this->type);
  param1->writeUTF(this->value);
}

void CheckFileMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CheckFileMessage(param1);
}

void CheckFileMessage::deserializeAs_CheckFileMessage(Reader *param1)
{
  this->filenameHash = param1->readUTF();
  this->type = param1->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - CheckFileMessage -"<<"Forbidden value (" << this->type << ") on element of CheckFileMessage.type.";
  }
  else
  {
    this->value = param1->readUTF();
    return;
  }
}

CheckFileMessage::CheckFileMessage()
{
  m_type = MessageEnum::CHECKFILEMESSAGE;
}

