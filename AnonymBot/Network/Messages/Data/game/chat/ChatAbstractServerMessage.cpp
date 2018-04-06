#include "ChatAbstractServerMessage.h"

void ChatAbstractServerMessage::serialize(Writer *param1)
{
  this->serializeAs_ChatAbstractServerMessage(param1);
}

void ChatAbstractServerMessage::serializeAs_ChatAbstractServerMessage(Writer *param1)
{
  param1->writeByte(this->channel);
  param1->writeUTF(this->content);
  if(this->timestamp < 0)
  {
    qDebug()<<"ERREUR - ChatAbstractServerMessage -"<<"Forbidden value (" << this->timestamp << ") on element timestamp.";
  }
  else
  {
    param1->writeInt((int)this->timestamp);
    param1->writeUTF(this->fingerprint);
    return;
  }
}

void ChatAbstractServerMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChatAbstractServerMessage(param1);
}

void ChatAbstractServerMessage::deserializeAs_ChatAbstractServerMessage(Reader *param1)
{
  this->channel = param1->readByte();
  if(this->channel < 0)
  {
    qDebug()<<"ERREUR - ChatAbstractServerMessage -"<<"Forbidden value (" << this->channel << ") on element of ChatAbstractServerMessage.channel.";
  }
  else
  {
    this->content = param1->readUTF();
    this->timestamp = param1->readInt();
    if(this->timestamp < 0)
    {
      qDebug()<<"ERREUR - ChatAbstractServerMessage -"<<"Forbidden value (" << this->timestamp << ") on element of ChatAbstractServerMessage.timestamp.";
    }
    else
    {
      this->fingerprint = param1->readUTF();
      return;
    }
  }
}

ChatAbstractServerMessage::ChatAbstractServerMessage()
{
  m_type = MessageEnum::CHATABSTRACTSERVERMESSAGE;
}

