#include "KrosmasterAuthTokenErrorMessage.h"

void KrosmasterAuthTokenErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_KrosmasterAuthTokenErrorMessage(param1);
}

void KrosmasterAuthTokenErrorMessage::serializeAs_KrosmasterAuthTokenErrorMessage(Writer *param1)
{
  param1->writeByte(this->reason);
}

void KrosmasterAuthTokenErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_KrosmasterAuthTokenErrorMessage(param1);
}

void KrosmasterAuthTokenErrorMessage::deserializeAs_KrosmasterAuthTokenErrorMessage(Reader *param1)
{
  this->reason = param1->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - KrosmasterAuthTokenErrorMessage -"<<"Forbidden value (" << this->reason << ") on element of KrosmasterAuthTokenErrorMessage.reason.";
  }
  else
  {
    return;
  }
}

KrosmasterAuthTokenErrorMessage::KrosmasterAuthTokenErrorMessage()
{
  m_type = MessageEnum::KROSMASTERAUTHTOKENERRORMESSAGE;
}

