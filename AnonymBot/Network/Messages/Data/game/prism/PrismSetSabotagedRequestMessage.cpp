#include "PrismSetSabotagedRequestMessage.h"

void PrismSetSabotagedRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_PrismSetSabotagedRequestMessage(param1);
}

void PrismSetSabotagedRequestMessage::serializeAs_PrismSetSabotagedRequestMessage(Writer *param1)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismSetSabotagedRequestMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  else
  {
    param1->writeVarShort((int)this->subAreaId);
    return;
  }
}

void PrismSetSabotagedRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PrismSetSabotagedRequestMessage(param1);
}

void PrismSetSabotagedRequestMessage::deserializeAs_PrismSetSabotagedRequestMessage(Reader *param1)
{
  this->subAreaId = param1->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismSetSabotagedRequestMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of PrismSetSabotagedRequestMessage.subAreaId.";
  }
  else
  {
    return;
  }
}

PrismSetSabotagedRequestMessage::PrismSetSabotagedRequestMessage()
{
  m_type = MessageEnum::PRISMSETSABOTAGEDREQUESTMESSAGE;
}

