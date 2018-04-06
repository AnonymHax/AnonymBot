#include "TaxCollectorMovementMessage.h"

void TaxCollectorMovementMessage::serialize(Writer *param1)
{
  this->serializeAs_TaxCollectorMovementMessage(param1);
}

void TaxCollectorMovementMessage::serializeAs_TaxCollectorMovementMessage(Writer *param1)
{
  param1->writeByte(this->movementType);
  this->basicInfos.serializeAs_TaxCollectorBasicInformations(param1);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorMovementMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  else
  {
    param1->writeVarLong((double)this->playerId);
    param1->writeUTF(this->playerName);
    return;
  }
}

void TaxCollectorMovementMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TaxCollectorMovementMessage(param1);
}

void TaxCollectorMovementMessage::deserializeAs_TaxCollectorMovementMessage(Reader *param1)
{
  this->movementType = param1->readByte();
  if(this->movementType < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorMovementMessage -"<<"Forbidden value (" << this->movementType << ") on element of TaxCollectorMovementMessage.movementType.";
  }
  else
  {
    this->basicInfos = TaxCollectorBasicInformations();
    this->basicInfos.deserialize(param1);
    this->playerId = param1->readVarUhLong();
    if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - TaxCollectorMovementMessage -"<<"Forbidden value (" << this->playerId << ") on element of TaxCollectorMovementMessage.playerId.";
    }
    else
    {
      this->playerName = param1->readUTF();
      return;
    }
  }
}

TaxCollectorMovementMessage::TaxCollectorMovementMessage()
{
  m_type = MessageEnum::TAXCOLLECTORMOVEMENTMESSAGE;
}

