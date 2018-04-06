#include "LockableStateUpdateStorageMessage.h"

void LockableStateUpdateStorageMessage::serialize(Writer *param1)
{
  this->serializeAs_LockableStateUpdateStorageMessage(param1);
}

void LockableStateUpdateStorageMessage::serializeAs_LockableStateUpdateStorageMessage(Writer *param1)
{
  LockableStateUpdateAbstractMessage::serializeAs_LockableStateUpdateAbstractMessage(param1);
  param1->writeInt((int)this->mapId);
  if(this->elementId < 0)
  {
    qDebug()<<"ERREUR - LockableStateUpdateStorageMessage -"<<"Forbidden value (" << this->elementId << ") on element elementId.";
  }
  else
  {
    param1->writeVarInt((int)this->elementId);
    return;
  }
}

void LockableStateUpdateStorageMessage::deserialize(Reader *param1)
{
  this->deserializeAs_LockableStateUpdateStorageMessage(param1);
}

void LockableStateUpdateStorageMessage::deserializeAs_LockableStateUpdateStorageMessage(Reader *param1)
{
  LockableStateUpdateAbstractMessage::deserialize(param1);
  this->mapId = param1->readInt();
  this->elementId = param1->readVarUhInt();
  if(this->elementId < 0)
  {
    qDebug()<<"ERREUR - LockableStateUpdateStorageMessage -"<<"Forbidden value (" << this->elementId << ") on element of LockableStateUpdateStorageMessage.elementId.";
  }
  else
  {
    return;
  }
}

LockableStateUpdateStorageMessage::LockableStateUpdateStorageMessage()
{
  m_type = MessageEnum::LOCKABLESTATEUPDATESTORAGEMESSAGE;
}

