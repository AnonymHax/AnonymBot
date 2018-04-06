#include "ChatServerMessage.h"

void ChatServerMessage::serialize(Writer *param1)
{
  this->serializeAs_ChatServerMessage(param1);
}

void ChatServerMessage::serializeAs_ChatServerMessage(Writer *param1)
{
  ChatAbstractServerMessage::serializeAs_ChatAbstractServerMessage(param1);
  if(this->senderId < -9.007199254740992E15 || this->senderId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ChatServerMessage -"<<"Forbidden value (" << this->senderId << ") on element senderId.";
  }
  else
  {
    param1->writeDouble(this->senderId);
    param1->writeUTF(this->senderName);
    if(this->senderAccountId < 0)
    {
      qDebug()<<"ERREUR - ChatServerMessage -"<<"Forbidden value (" << this->senderAccountId << ") on element senderAccountId.";
    }
    else
    {
      param1->writeInt((int)this->senderAccountId);
      return;
    }
  }
}

void ChatServerMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChatServerMessage(param1);
}

void ChatServerMessage::deserializeAs_ChatServerMessage(Reader *param1)
{
  ChatAbstractServerMessage::deserialize(param1);
  this->senderId = param1->readDouble();
  if(this->senderId < -9.007199254740992E15 || this->senderId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ChatServerMessage -"<<"Forbidden value (" << this->senderId << ") on element of ChatServerMessage.senderId.";
  }
  else
  {
    this->senderName = param1->readUTF();
    this->senderAccountId = param1->readInt();
    if(this->senderAccountId < 0)
    {
      qDebug()<<"ERREUR - ChatServerMessage -"<<"Forbidden value (" << this->senderAccountId << ") on element of ChatServerMessage.senderAccountId.";
    }
    else
    {
      return;
    }
  }
}

ChatServerMessage::ChatServerMessage()
{
  m_type = MessageEnum::CHATSERVERMESSAGE;
}

