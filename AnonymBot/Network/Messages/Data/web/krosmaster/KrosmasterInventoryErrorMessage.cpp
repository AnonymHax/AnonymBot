#include "KrosmasterInventoryErrorMessage.h"

void KrosmasterInventoryErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_KrosmasterInventoryErrorMessage(param1);
}

void KrosmasterInventoryErrorMessage::serializeAs_KrosmasterInventoryErrorMessage(Writer *param1)
{
  param1->writeByte(this->reason);
}

void KrosmasterInventoryErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_KrosmasterInventoryErrorMessage(param1);
}

void KrosmasterInventoryErrorMessage::deserializeAs_KrosmasterInventoryErrorMessage(Reader *param1)
{
  this->reason = param1->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - KrosmasterInventoryErrorMessage -"<<"Forbidden value (" << this->reason << ") on element of KrosmasterInventoryErrorMessage.reason.";
  }
  else
  {
    return;
  }
}

KrosmasterInventoryErrorMessage::KrosmasterInventoryErrorMessage()
{
  m_type = MessageEnum::KROSMASTERINVENTORYERRORMESSAGE;
}

