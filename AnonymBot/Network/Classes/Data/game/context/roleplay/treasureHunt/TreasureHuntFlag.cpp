#include "TreasureHuntFlag.h"

void TreasureHuntFlag::serialize(Writer *param1)
{
  this->serializeAs_TreasureHuntFlag(param1);
}

void TreasureHuntFlag::serializeAs_TreasureHuntFlag(Writer *param1)
{
  param1->writeInt((int)this->mapId);
  param1->writeByte(this->state);
}

void TreasureHuntFlag::deserialize(Reader *param1)
{
  this->deserializeAs_TreasureHuntFlag(param1);
}

void TreasureHuntFlag::deserializeAs_TreasureHuntFlag(Reader *param1)
{
  this->mapId = param1->readInt();
  this->state = param1->readByte();
  if(this->state < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntFlag -"<<"Forbidden value (" << this->state << ") on element of TreasureHuntFlag.state.";
  }
  else
  {
    return;
  }
}

TreasureHuntFlag::TreasureHuntFlag()
{
  m_types<<ClassEnum::TREASUREHUNTFLAG;
}

bool TreasureHuntFlag::operator==(const TreasureHuntFlag &compared)
{
  if(mapId == compared.mapId)
  if(state == compared.state)
  return true;
  
  return false;
}

