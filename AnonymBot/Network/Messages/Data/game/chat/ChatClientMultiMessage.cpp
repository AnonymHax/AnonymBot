#include "ChatClientMultiMessage.h"

void ChatClientMultiMessage::serialize(Writer *param1)
{
  this->serializeAs_ChatClientMultiMessage(param1);
}

void ChatClientMultiMessage::serializeAs_ChatClientMultiMessage(Writer *param1)
{
  ChatAbstractClientMessage::serializeAs_ChatAbstractClientMessage(param1);
  param1->writeByte(this->channel);
}

void ChatClientMultiMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChatClientMultiMessage(param1);
}

void ChatClientMultiMessage::deserializeAs_ChatClientMultiMessage(Reader *param1)
{
  ChatAbstractClientMessage::deserialize(param1);
  this->channel = param1->readByte();
  if(this->channel < 0)
  {
    qDebug()<<"ERREUR - ChatClientMultiMessage -"<<"Forbidden value (" << this->channel << ") on element of ChatClientMultiMessage.channel.";
  }
  else
  {
    return;
  }
}

ChatClientMultiMessage::ChatClientMultiMessage()
{
  m_type = MessageEnum::CHATCLIENTMULTIMESSAGE;
  m_needsHash = true;
}

