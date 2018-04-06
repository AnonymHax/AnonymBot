#include "TaxCollectorMovement.h"

void TaxCollectorMovement::serialize(Writer *param1)
{
  this->serializeAs_TaxCollectorMovement(param1);
}

void TaxCollectorMovement::serializeAs_TaxCollectorMovement(Writer *param1)
{
  param1->writeByte(this->movementType);
  this->basicInfos.serializeAs_TaxCollectorBasicInformations(param1);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorMovement -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  else
  {
    param1->writeVarLong((double)this->playerId);
    param1->writeUTF(this->playerName);
    return;
  }
}

void TaxCollectorMovement::deserialize(Reader *param1)
{
  this->deserializeAs_TaxCollectorMovement(param1);
}

void TaxCollectorMovement::deserializeAs_TaxCollectorMovement(Reader *param1)
{
  this->movementType = param1->readByte();
  if(this->movementType < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorMovement -"<<"Forbidden value (" << this->movementType << ") on element of TaxCollectorMovement.movementType.";
  }
  else
  {
    this->basicInfos = TaxCollectorBasicInformations();
    this->basicInfos.deserialize(param1);
    this->playerId = param1->readVarUhLong();
    if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - TaxCollectorMovement -"<<"Forbidden value (" << this->playerId << ") on element of TaxCollectorMovement.playerId.";
    }
    else
    {
      this->playerName = param1->readUTF();
      return;
    }
  }
}

TaxCollectorMovement::TaxCollectorMovement()
{
  m_types<<ClassEnum::TAXCOLLECTORMOVEMENT;
}

bool TaxCollectorMovement::operator==(const TaxCollectorMovement &compared)
{
  if(movementType == compared.movementType)
  if(basicInfos == compared.basicInfos)
  if(playerId == compared.playerId)
  if(playerName == compared.playerName)
  return true;
  
  return false;
}

