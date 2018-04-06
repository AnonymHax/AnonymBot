#include "ChatErrorMessage.h"

void ChatErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_ChatErrorMessage(param1);
}

void ChatErrorMessage::serializeAs_ChatErrorMessage(Writer *param1)
{
  param1->writeByte(this->reason);
}

void ChatErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChatErrorMessage(param1);
}

void ChatErrorMessage::deserializeAs_ChatErrorMessage(Reader *param1)
{
  this->reason = param1->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - ChatErrorMessage -"<<"Forbidden value (" << this->reason << ") on element of ChatErrorMessage.reason.";
  }
  else
  {
    return;
  }
}

ChatErrorMessage::ChatErrorMessage()
{
  m_type = MessageEnum::CHATERRORMESSAGE;
}

