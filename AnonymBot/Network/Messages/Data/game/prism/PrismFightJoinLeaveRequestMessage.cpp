#include "PrismFightJoinLeaveRequestMessage.h"

void PrismFightJoinLeaveRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_PrismFightJoinLeaveRequestMessage(param1);
}

void PrismFightJoinLeaveRequestMessage::serializeAs_PrismFightJoinLeaveRequestMessage(Writer *param1)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightJoinLeaveRequestMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  else
  {
    param1->writeVarShort((int)this->subAreaId);
    param1->writeBool(this->join);
    return;
  }
}

void PrismFightJoinLeaveRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PrismFightJoinLeaveRequestMessage(param1);
}

void PrismFightJoinLeaveRequestMessage::deserializeAs_PrismFightJoinLeaveRequestMessage(Reader *param1)
{
  this->subAreaId = param1->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightJoinLeaveRequestMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of PrismFightJoinLeaveRequestMessage.subAreaId.";
  }
  else
  {
    this->join = param1->readBool();
    return;
  }
}

PrismFightJoinLeaveRequestMessage::PrismFightJoinLeaveRequestMessage()
{
  m_type = MessageEnum::PRISMFIGHTJOINLEAVEREQUESTMESSAGE;
}

