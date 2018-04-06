#include "AcquaintanceSearchMessage.h"

void AcquaintanceSearchMessage::serialize(Writer *param1)
{
  this->serializeAs_AcquaintanceSearchMessage(param1);
}

void AcquaintanceSearchMessage::serializeAs_AcquaintanceSearchMessage(Writer *param1)
{
  param1->writeUTF(this->nickname);
}

void AcquaintanceSearchMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AcquaintanceSearchMessage(param1);
}

void AcquaintanceSearchMessage::deserializeAs_AcquaintanceSearchMessage(Reader *param1)
{
  this->nickname = param1->readUTF();
}

AcquaintanceSearchMessage::AcquaintanceSearchMessage()
{
  m_type = MessageEnum::ACQUAINTANCESEARCHMESSAGE;
}

