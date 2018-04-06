#include "LockableStateUpdateHouseDoorMessage.h"

void LockableStateUpdateHouseDoorMessage::serialize(Writer *param1)
{
  this->serializeAs_LockableStateUpdateHouseDoorMessage(param1);
}

void LockableStateUpdateHouseDoorMessage::serializeAs_LockableStateUpdateHouseDoorMessage(Writer *param1)
{
  LockableStateUpdateAbstractMessage::serializeAs_LockableStateUpdateAbstractMessage(param1);
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - LockableStateUpdateHouseDoorMessage -"<<"Forbidden value (" << this->houseId << ") on element houseId.";
  }
  else
  {
    param1->writeVarInt((int)this->houseId);
    return;
  }
}

void LockableStateUpdateHouseDoorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_LockableStateUpdateHouseDoorMessage(param1);
}

void LockableStateUpdateHouseDoorMessage::deserializeAs_LockableStateUpdateHouseDoorMessage(Reader *param1)
{
  LockableStateUpdateAbstractMessage::deserialize(param1);
  this->houseId = param1->readVarUhInt();
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - LockableStateUpdateHouseDoorMessage -"<<"Forbidden value (" << this->houseId << ") on element of LockableStateUpdateHouseDoorMessage.houseId.";
  }
  else
  {
    return;
  }
}

LockableStateUpdateHouseDoorMessage::LockableStateUpdateHouseDoorMessage()
{
  m_type = MessageEnum::LOCKABLESTATEUPDATEHOUSEDOORMESSAGE;
}

