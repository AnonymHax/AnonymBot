#include "IgnoredAddFailureMessage.h"

void IgnoredAddFailureMessage::serialize(Writer *param1)
{
  this->serializeAs_IgnoredAddFailureMessage(param1);
}

void IgnoredAddFailureMessage::serializeAs_IgnoredAddFailureMessage(Writer *param1)
{
  param1->writeByte(this->reason);
}

void IgnoredAddFailureMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IgnoredAddFailureMessage(param1);
}

void IgnoredAddFailureMessage::deserializeAs_IgnoredAddFailureMessage(Reader *param1)
{
  this->reason = param1->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - IgnoredAddFailureMessage -"<<"Forbidden value (" << this->reason << ") on element of IgnoredAddFailureMessage.reason.";
  }
  else
  {
    return;
  }
}

IgnoredAddFailureMessage::IgnoredAddFailureMessage()
{
  m_type = MessageEnum::IGNOREDADDFAILUREMESSAGE;
}

