#include "FinishMoveInformations.h"

void FinishMoveInformations::serialize(Writer *param1)
{
  this->serializeAs_FinishMoveInformations(param1);
}

void FinishMoveInformations::serializeAs_FinishMoveInformations(Writer *param1)
{
  if(this->finishMoveId < 0)
  {
    qDebug()<<"ERREUR - FinishMoveInformations -"<<"Forbidden value (" << this->finishMoveId << ") on element finishMoveId.";
  }
  else
  {
    param1->writeInt((int)this->finishMoveId);
    param1->writeBool(this->finishMoveState);
    return;
  }
}

void FinishMoveInformations::deserialize(Reader *param1)
{
  this->deserializeAs_FinishMoveInformations(param1);
}

void FinishMoveInformations::deserializeAs_FinishMoveInformations(Reader *param1)
{
  this->finishMoveId = param1->readInt();
  if(this->finishMoveId < 0)
  {
    qDebug()<<"ERREUR - FinishMoveInformations -"<<"Forbidden value (" << this->finishMoveId << ") on element of FinishMoveInformations.finishMoveId.";
  }
  else
  {
    this->finishMoveState = param1->readBool();
    return;
  }
}

FinishMoveInformations::FinishMoveInformations()
{
  m_types<<ClassEnum::FINISHMOVEINFORMATIONS;
}

bool FinishMoveInformations::operator==(const FinishMoveInformations &compared)
{
  if(finishMoveId == compared.finishMoveId)
  if(finishMoveState == compared.finishMoveState)
  return true;
  
  return false;
}

