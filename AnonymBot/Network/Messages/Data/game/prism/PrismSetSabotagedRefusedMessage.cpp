#include "PrismSetSabotagedRefusedMessage.h"

void PrismSetSabotagedRefusedMessage::serialize(Writer *param1)
{
  this->serializeAs_PrismSetSabotagedRefusedMessage(param1);
}

void PrismSetSabotagedRefusedMessage::serializeAs_PrismSetSabotagedRefusedMessage(Writer *param1)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismSetSabotagedRefusedMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  else
  {
    param1->writeVarShort((int)this->subAreaId);
    param1->writeByte(this->reason);
    return;
  }
}

void PrismSetSabotagedRefusedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PrismSetSabotagedRefusedMessage(param1);
}

void PrismSetSabotagedRefusedMessage::deserializeAs_PrismSetSabotagedRefusedMessage(Reader *param1)
{
  this->subAreaId = param1->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismSetSabotagedRefusedMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of PrismSetSabotagedRefusedMessage.subAreaId.";
  }
  else
  {
    this->reason = param1->readByte();
    return;
  }
}

PrismSetSabotagedRefusedMessage::PrismSetSabotagedRefusedMessage()
{
  m_type = MessageEnum::PRISMSETSABOTAGEDREFUSEDMESSAGE;
}

