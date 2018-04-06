#include "ChatMessageReportMessage.h"

void ChatMessageReportMessage::serialize(Writer *param1)
{
  this->serializeAs_ChatMessageReportMessage(param1);
}

void ChatMessageReportMessage::serializeAs_ChatMessageReportMessage(Writer *param1)
{
  param1->writeUTF(this->senderName);
  param1->writeUTF(this->content);
  if(this->timestamp < 0)
  {
    qDebug()<<"ERREUR - ChatMessageReportMessage -"<<"Forbidden value (" << this->timestamp << ") on element timestamp.";
  }
  else
  {
    param1->writeInt((int)this->timestamp);
    param1->writeByte(this->channel);
    param1->writeUTF(this->fingerprint);
    if(this->reason < 0)
    {
      qDebug()<<"ERREUR - ChatMessageReportMessage -"<<"Forbidden value (" << this->reason << ") on element reason.";
    }
    else
    {
      param1->writeByte(this->reason);
      return;
    }
  }
}

void ChatMessageReportMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChatMessageReportMessage(param1);
}

void ChatMessageReportMessage::deserializeAs_ChatMessageReportMessage(Reader *param1)
{
  this->senderName = param1->readUTF();
  this->content = param1->readUTF();
  this->timestamp = param1->readInt();
  if(this->timestamp < 0)
  {
    qDebug()<<"ERREUR - ChatMessageReportMessage -"<<"Forbidden value (" << this->timestamp << ") on element of ChatMessageReportMessage.timestamp.";
  }
  else
  {
    this->channel = param1->readByte();
    if(this->channel < 0)
    {
      qDebug()<<"ERREUR - ChatMessageReportMessage -"<<"Forbidden value (" << this->channel << ") on element of ChatMessageReportMessage.channel.";
    }
    else
    {
      this->fingerprint = param1->readUTF();
      this->reason = param1->readByte();
      if(this->reason < 0)
      {
        qDebug()<<"ERREUR - ChatMessageReportMessage -"<<"Forbidden value (" << this->reason << ") on element of ChatMessageReportMessage.reason.";
      }
      else
      {
        return;
      }
    }
  }
}

ChatMessageReportMessage::ChatMessageReportMessage()
{
  m_type = MessageEnum::CHATMESSAGEREPORTMESSAGE;
}

