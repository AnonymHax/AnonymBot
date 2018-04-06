#include "ChatSmileyMessage.h"

void ChatSmileyMessage::serialize(Writer *param1)
{
  this->serializeAs_ChatSmileyMessage(param1);
}

void ChatSmileyMessage::serializeAs_ChatSmileyMessage(Writer *param1)
{
  if(this->entityId < -9.007199254740992E15 || this->entityId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ChatSmileyMessage -"<<"Forbidden value (" << this->entityId << ") on element entityId.";
  }
  else
  {
    param1->writeDouble(this->entityId);
    if(this->smileyId < 0)
    {
      qDebug()<<"ERREUR - ChatSmileyMessage -"<<"Forbidden value (" << this->smileyId << ") on element smileyId.";
    }
    else
    {
      param1->writeVarShort((int)this->smileyId);
      if(this->accountId < 0)
      {
        qDebug()<<"ERREUR - ChatSmileyMessage -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
      }
      else
      {
        param1->writeInt((int)this->accountId);
        return;
      }
    }
  }
}

void ChatSmileyMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChatSmileyMessage(param1);
}

void ChatSmileyMessage::deserializeAs_ChatSmileyMessage(Reader *param1)
{
  this->entityId = param1->readDouble();
  if(this->entityId < -9.007199254740992E15 || this->entityId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ChatSmileyMessage -"<<"Forbidden value (" << this->entityId << ") on element of ChatSmileyMessage.entityId.";
  }
  else
  {
    this->smileyId = param1->readVarUhShort();
    if(this->smileyId < 0)
    {
      qDebug()<<"ERREUR - ChatSmileyMessage -"<<"Forbidden value (" << this->smileyId << ") on element of ChatSmileyMessage.smileyId.";
    }
    else
    {
      this->accountId = param1->readInt();
      if(this->accountId < 0)
      {
        qDebug()<<"ERREUR - ChatSmileyMessage -"<<"Forbidden value (" << this->accountId << ") on element of ChatSmileyMessage.accountId.";
      }
      else
      {
        return;
      }
    }
  }
}

ChatSmileyMessage::ChatSmileyMessage()
{
  m_type = MessageEnum::CHATSMILEYMESSAGE;
}

