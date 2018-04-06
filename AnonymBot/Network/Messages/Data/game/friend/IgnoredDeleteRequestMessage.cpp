#include "IgnoredDeleteRequestMessage.h"

void IgnoredDeleteRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_IgnoredDeleteRequestMessage(param1);
}

void IgnoredDeleteRequestMessage::serializeAs_IgnoredDeleteRequestMessage(Writer *param1)
{
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - IgnoredDeleteRequestMessage -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
  }
  else
  {
    param1->writeInt((int)this->accountId);
    param1->writeBool(this->session);
    return;
  }
}

void IgnoredDeleteRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IgnoredDeleteRequestMessage(param1);
}

void IgnoredDeleteRequestMessage::deserializeAs_IgnoredDeleteRequestMessage(Reader *param1)
{
  this->accountId = param1->readInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - IgnoredDeleteRequestMessage -"<<"Forbidden value (" << this->accountId << ") on element of IgnoredDeleteRequestMessage.accountId.";
  }
  else
  {
    this->session = param1->readBool();
    return;
  }
}

IgnoredDeleteRequestMessage::IgnoredDeleteRequestMessage()
{
  m_type = MessageEnum::IGNOREDDELETEREQUESTMESSAGE;
}

