#include "URLOpenMessage.h"

void URLOpenMessage::serialize(Writer *param1)
{
  this->serializeAs_URLOpenMessage(param1);
}

void URLOpenMessage::serializeAs_URLOpenMessage(Writer *param1)
{
  if(this->urlId < 0)
  {
    qDebug()<<"ERREUR - URLOpenMessage -"<<"Forbidden value (" << this->urlId << ") on element urlId.";
  }
  else
  {
    param1->writeByte(this->urlId);
    return;
  }
}

void URLOpenMessage::deserialize(Reader *param1)
{
  this->deserializeAs_URLOpenMessage(param1);
}

void URLOpenMessage::deserializeAs_URLOpenMessage(Reader *param1)
{
  this->urlId = param1->readByte();
  if(this->urlId < 0)
  {
    qDebug()<<"ERREUR - URLOpenMessage -"<<"Forbidden value (" << this->urlId << ") on element of URLOpenMessage.urlId.";
  }
  else
  {
    return;
  }
}

URLOpenMessage::URLOpenMessage()
{
  m_type = MessageEnum::URLOPENMESSAGE;
}

