#include "ChatServerCopyMessage.h"

void ChatServerCopyMessage::serialize(Writer *param1)
{
  this->serializeAs_ChatServerCopyMessage(param1);
}

void ChatServerCopyMessage::serializeAs_ChatServerCopyMessage(Writer *param1)
{
  ChatAbstractServerMessage::serializeAs_ChatAbstractServerMessage(param1);
  if(this->receiverId < 0 || this->receiverId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ChatServerCopyMessage -"<<"Forbidden value (" << this->receiverId << ") on element receiverId.";
  }
  else
  {
    param1->writeVarLong((double)this->receiverId);
    param1->writeUTF(this->receiverName);
    return;
  }
}

void ChatServerCopyMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChatServerCopyMessage(param1);
}

void ChatServerCopyMessage::deserializeAs_ChatServerCopyMessage(Reader *param1)
{
  ChatAbstractServerMessage::deserialize(param1);
  this->receiverId = param1->readVarUhLong();
  if(this->receiverId < 0 || this->receiverId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ChatServerCopyMessage -"<<"Forbidden value (" << this->receiverId << ") on element of ChatServerCopyMessage.receiverId.";
  }
  else
  {
    this->receiverName = param1->readUTF();
    return;
  }
}

ChatServerCopyMessage::ChatServerCopyMessage()
{
  m_type = MessageEnum::CHATSERVERCOPYMESSAGE;
}

