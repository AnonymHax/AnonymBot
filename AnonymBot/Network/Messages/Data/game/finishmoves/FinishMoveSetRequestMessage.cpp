#include "FinishMoveSetRequestMessage.h"

void FinishMoveSetRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_FinishMoveSetRequestMessage(param1);
}

void FinishMoveSetRequestMessage::serializeAs_FinishMoveSetRequestMessage(Writer *param1)
{
  if(this->finishMoveId < 0)
  {
    qDebug()<<"ERREUR - FinishMoveSetRequestMessage -"<<"Forbidden value (" << this->finishMoveId << ") on element finishMoveId.";
  }
  else
  {
    param1->writeInt((int)this->finishMoveId);
    param1->writeBool(this->finishMoveState);
    return;
  }
}

void FinishMoveSetRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_FinishMoveSetRequestMessage(param1);
}

void FinishMoveSetRequestMessage::deserializeAs_FinishMoveSetRequestMessage(Reader *param1)
{
  this->finishMoveId = param1->readInt();
  if(this->finishMoveId < 0)
  {
    qDebug()<<"ERREUR - FinishMoveSetRequestMessage -"<<"Forbidden value (" << this->finishMoveId << ") on element of FinishMoveSetRequestMessage.finishMoveId.";
  }
  else
  {
    this->finishMoveState = param1->readBool();
    return;
  }
}

FinishMoveSetRequestMessage::FinishMoveSetRequestMessage()
{
  m_type = MessageEnum::FINISHMOVESETREQUESTMESSAGE;
}

