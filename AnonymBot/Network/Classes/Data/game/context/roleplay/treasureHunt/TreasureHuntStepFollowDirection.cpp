#include "TreasureHuntStepFollowDirection.h"

void TreasureHuntStepFollowDirection::serialize(Writer *param1)
{
  this->serializeAs_TreasureHuntStepFollowDirection(param1);
}

void TreasureHuntStepFollowDirection::serializeAs_TreasureHuntStepFollowDirection(Writer *param1)
{
  TreasureHuntStep::serializeAs_TreasureHuntStep(param1);
  param1->writeByte(this->direction);
  if(this->mapCount < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntStepFollowDirection -"<<"Forbidden value (" << this->mapCount << ") on element mapCount.";
  }
  else
  {
    param1->writeVarShort((int)this->mapCount);
    return;
  }
}

void TreasureHuntStepFollowDirection::deserialize(Reader *param1)
{
  this->deserializeAs_TreasureHuntStepFollowDirection(param1);
}

void TreasureHuntStepFollowDirection::deserializeAs_TreasureHuntStepFollowDirection(Reader *param1)
{
  TreasureHuntStep::deserialize(param1);
  this->direction = param1->readByte();
  if(this->direction < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntStepFollowDirection -"<<"Forbidden value (" << this->direction << ") on element of TreasureHuntStepFollowDirection.direction.";
  }
  else
  {
    this->mapCount = param1->readVarUhShort();
    if(this->mapCount < 0)
    {
      qDebug()<<"ERREUR - TreasureHuntStepFollowDirection -"<<"Forbidden value (" << this->mapCount << ") on element of TreasureHuntStepFollowDirection.mapCount.";
    }
    else
    {
      return;
    }
  }
}

TreasureHuntStepFollowDirection::TreasureHuntStepFollowDirection()
{
  m_types<<ClassEnum::TREASUREHUNTSTEPFOLLOWDIRECTION;
}

bool TreasureHuntStepFollowDirection::operator==(const TreasureHuntStepFollowDirection &compared)
{
  if(direction == compared.direction)
  if(mapCount == compared.mapCount)
  return true;
  
  return false;
}

