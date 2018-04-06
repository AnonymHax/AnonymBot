#include "TreasureHuntStepFollowDirectionToHint.h"

void TreasureHuntStepFollowDirectionToHint::serialize(Writer *param1)
{
  this->serializeAs_TreasureHuntStepFollowDirectionToHint(param1);
}

void TreasureHuntStepFollowDirectionToHint::serializeAs_TreasureHuntStepFollowDirectionToHint(Writer *param1)
{
  TreasureHuntStep::serializeAs_TreasureHuntStep(param1);
  param1->writeByte(this->direction);
  if(this->npcId < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntStepFollowDirectionToHint -"<<"Forbidden value (" << this->npcId << ") on element npcId.";
  }
  else
  {
    param1->writeVarShort((int)this->npcId);
    return;
  }
}

void TreasureHuntStepFollowDirectionToHint::deserialize(Reader *param1)
{
  this->deserializeAs_TreasureHuntStepFollowDirectionToHint(param1);
}

void TreasureHuntStepFollowDirectionToHint::deserializeAs_TreasureHuntStepFollowDirectionToHint(Reader *param1)
{
  TreasureHuntStep::deserialize(param1);
  this->direction = param1->readByte();
  if(this->direction < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntStepFollowDirectionToHint -"<<"Forbidden value (" << this->direction << ") on element of TreasureHuntStepFollowDirectionToHint.direction.";
  }
  else
  {
    this->npcId = param1->readVarUhShort();
    if(this->npcId < 0)
    {
      qDebug()<<"ERREUR - TreasureHuntStepFollowDirectionToHint -"<<"Forbidden value (" << this->npcId << ") on element of TreasureHuntStepFollowDirectionToHint.npcId.";
    }
    else
    {
      return;
    }
  }
}

TreasureHuntStepFollowDirectionToHint::TreasureHuntStepFollowDirectionToHint()
{
  m_types<<ClassEnum::TREASUREHUNTSTEPFOLLOWDIRECTIONTOHINT;
}

bool TreasureHuntStepFollowDirectionToHint::operator==(const TreasureHuntStepFollowDirectionToHint &compared)
{
  if(direction == compared.direction)
  if(npcId == compared.npcId)
  return true;
  
  return false;
}

