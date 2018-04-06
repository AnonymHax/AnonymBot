#include "TreasureHuntStepFollowDirectionToPOI.h"

void TreasureHuntStepFollowDirectionToPOI::serialize(Writer *param1)
{
  this->serializeAs_TreasureHuntStepFollowDirectionToPOI(param1);
}

void TreasureHuntStepFollowDirectionToPOI::serializeAs_TreasureHuntStepFollowDirectionToPOI(Writer *param1)
{
  TreasureHuntStep::serializeAs_TreasureHuntStep(param1);
  param1->writeByte(this->direction);
  if(this->poiLabelId < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntStepFollowDirectionToPOI -"<<"Forbidden value (" << this->poiLabelId << ") on element poiLabelId.";
  }
  else
  {
    param1->writeVarShort((int)this->poiLabelId);
    return;
  }
}

void TreasureHuntStepFollowDirectionToPOI::deserialize(Reader *param1)
{
  this->deserializeAs_TreasureHuntStepFollowDirectionToPOI(param1);
}

void TreasureHuntStepFollowDirectionToPOI::deserializeAs_TreasureHuntStepFollowDirectionToPOI(Reader *param1)
{
  TreasureHuntStep::deserialize(param1);
  this->direction = param1->readByte();
  if(this->direction < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntStepFollowDirectionToPOI -"<<"Forbidden value (" << this->direction << ") on element of TreasureHuntStepFollowDirectionToPOI.direction.";
  }
  else
  {
    this->poiLabelId = param1->readVarUhShort();
    if(this->poiLabelId < 0)
    {
      qDebug()<<"ERREUR - TreasureHuntStepFollowDirectionToPOI -"<<"Forbidden value (" << this->poiLabelId << ") on element of TreasureHuntStepFollowDirectionToPOI.poiLabelId.";
    }
    else
    {
      return;
    }
  }
}

TreasureHuntStepFollowDirectionToPOI::TreasureHuntStepFollowDirectionToPOI()
{
  m_types<<ClassEnum::TREASUREHUNTSTEPFOLLOWDIRECTIONTOPOI;
}

bool TreasureHuntStepFollowDirectionToPOI::operator==(const TreasureHuntStepFollowDirectionToPOI &compared)
{
  if(direction == compared.direction)
  if(poiLabelId == compared.poiLabelId)
  return true;
  
  return false;
}

