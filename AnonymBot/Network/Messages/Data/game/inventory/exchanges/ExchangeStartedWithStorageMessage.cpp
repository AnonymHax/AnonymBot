#include "ExchangeStartedWithStorageMessage.h"

void ExchangeStartedWithStorageMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeStartedWithStorageMessage(param1);
}

void ExchangeStartedWithStorageMessage::serializeAs_ExchangeStartedWithStorageMessage(Writer *param1)
{
  ExchangeStartedMessage::serializeAs_ExchangeStartedMessage(param1);
  if(this->storageMaxSlot < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartedWithStorageMessage -"<<"Forbidden value (" << this->storageMaxSlot << ") on element storageMaxSlot.";
  }
  else
  {
    param1->writeVarInt((int)this->storageMaxSlot);
    return;
  }
}

void ExchangeStartedWithStorageMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeStartedWithStorageMessage(param1);
}

void ExchangeStartedWithStorageMessage::deserializeAs_ExchangeStartedWithStorageMessage(Reader *param1)
{
  ExchangeStartedMessage::deserialize(param1);
  this->storageMaxSlot = param1->readVarUhInt();
  if(this->storageMaxSlot < 0)
  {
    qDebug()<<"ERREUR - ExchangeStartedWithStorageMessage -"<<"Forbidden value (" << this->storageMaxSlot << ") on element of ExchangeStartedWithStorageMessage.storageMaxSlot.";
  }
  else
  {
    return;
  }
}

ExchangeStartedWithStorageMessage::ExchangeStartedWithStorageMessage()
{
  m_type = MessageEnum::EXCHANGESTARTEDWITHSTORAGEMESSAGE;
}

