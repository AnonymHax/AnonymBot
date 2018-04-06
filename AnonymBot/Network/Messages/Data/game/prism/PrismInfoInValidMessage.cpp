#include "PrismInfoInValidMessage.h"

void PrismInfoInValidMessage::serialize(Writer *param1)
{
  this->serializeAs_PrismInfoInValidMessage(param1);
}

void PrismInfoInValidMessage::serializeAs_PrismInfoInValidMessage(Writer *param1)
{
  param1->writeByte(this->reason);
}

void PrismInfoInValidMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PrismInfoInValidMessage(param1);
}

void PrismInfoInValidMessage::deserializeAs_PrismInfoInValidMessage(Reader *param1)
{
  this->reason = param1->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - PrismInfoInValidMessage -"<<"Forbidden value (" << this->reason << ") on element of PrismInfoInValidMessage.reason.";
  }
  else
  {
    return;
  }
}

PrismInfoInValidMessage::PrismInfoInValidMessage()
{
  m_type = MessageEnum::PRISMINFOINVALIDMESSAGE;
}

