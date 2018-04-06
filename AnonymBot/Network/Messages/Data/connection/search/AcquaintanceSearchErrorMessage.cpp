#include "AcquaintanceSearchErrorMessage.h"

void AcquaintanceSearchErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_AcquaintanceSearchErrorMessage(param1);
}

void AcquaintanceSearchErrorMessage::serializeAs_AcquaintanceSearchErrorMessage(Writer *param1)
{
  param1->writeByte(this->reason);
}

void AcquaintanceSearchErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AcquaintanceSearchErrorMessage(param1);
}

void AcquaintanceSearchErrorMessage::deserializeAs_AcquaintanceSearchErrorMessage(Reader *param1)
{
  this->reason = param1->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - AcquaintanceSearchErrorMessage -"<<"Forbidden value (" << this->reason << ") on element of AcquaintanceSearchErrorMessage.reason.";
  }
  else
  {
    return;
  }
}

AcquaintanceSearchErrorMessage::AcquaintanceSearchErrorMessage()
{
  m_type = MessageEnum::ACQUAINTANCESEARCHERRORMESSAGE;
}

