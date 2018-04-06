#include "ChatSmileyRequestMessage.h"

void ChatSmileyRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_ChatSmileyRequestMessage(param1);
}

void ChatSmileyRequestMessage::serializeAs_ChatSmileyRequestMessage(Writer *param1)
{
  if(this->smileyId < 0)
  {
    qDebug()<<"ERREUR - ChatSmileyRequestMessage -"<<"Forbidden value (" << this->smileyId << ") on element smileyId.";
  }
  else
  {
    param1->writeVarShort((int)this->smileyId);
    return;
  }
}

void ChatSmileyRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChatSmileyRequestMessage(param1);
}

void ChatSmileyRequestMessage::deserializeAs_ChatSmileyRequestMessage(Reader *param1)
{
  this->smileyId = param1->readVarUhShort();
  if(this->smileyId < 0)
  {
    qDebug()<<"ERREUR - ChatSmileyRequestMessage -"<<"Forbidden value (" << this->smileyId << ") on element of ChatSmileyRequestMessage.smileyId.";
  }
  else
  {
    return;
  }
}

ChatSmileyRequestMessage::ChatSmileyRequestMessage()
{
  m_type = MessageEnum::CHATSMILEYREQUESTMESSAGE;
}

