#include "TitleSelectErrorMessage.h"

void TitleSelectErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_TitleSelectErrorMessage(param1);
}

void TitleSelectErrorMessage::serializeAs_TitleSelectErrorMessage(Writer *param1)
{
  param1->writeByte(this->reason);
}

void TitleSelectErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TitleSelectErrorMessage(param1);
}

void TitleSelectErrorMessage::deserializeAs_TitleSelectErrorMessage(Reader *param1)
{
  this->reason = param1->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - TitleSelectErrorMessage -"<<"Forbidden value (" << this->reason << ") on element of TitleSelectErrorMessage.reason.";
  }
  else
  {
    return;
  }
}

TitleSelectErrorMessage::TitleSelectErrorMessage()
{
  m_type = MessageEnum::TITLESELECTERRORMESSAGE;
}

