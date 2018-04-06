#include "CheckFileRequestMessage.h"

void CheckFileRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_CheckFileRequestMessage(param1);
}

void CheckFileRequestMessage::serializeAs_CheckFileRequestMessage(Writer *param1)
{
  param1->writeUTF(this->filename);
  param1->writeByte(this->type);
}

void CheckFileRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CheckFileRequestMessage(param1);
}

void CheckFileRequestMessage::deserializeAs_CheckFileRequestMessage(Reader *param1)
{
  this->filename = param1->readUTF();
  this->type = param1->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - CheckFileRequestMessage -"<<"Forbidden value (" << this->type << ") on element of CheckFileRequestMessage.type.";
  }
  else
  {
    return;
  }
}

CheckFileRequestMessage::CheckFileRequestMessage()
{
  m_type = MessageEnum::CHECKFILEREQUESTMESSAGE;
}

