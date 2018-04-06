#include "TreasureHuntAvailableRetryCountUpdateMessage.h"

void TreasureHuntAvailableRetryCountUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_TreasureHuntAvailableRetryCountUpdateMessage(param1);
}

void TreasureHuntAvailableRetryCountUpdateMessage::serializeAs_TreasureHuntAvailableRetryCountUpdateMessage(Writer *param1)
{
  param1->writeByte(this->questType);
  param1->writeInt((int)this->availableRetryCount);
}

void TreasureHuntAvailableRetryCountUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TreasureHuntAvailableRetryCountUpdateMessage(param1);
}

void TreasureHuntAvailableRetryCountUpdateMessage::deserializeAs_TreasureHuntAvailableRetryCountUpdateMessage(Reader *param1)
{
  this->questType = param1->readByte();
  if(this->questType < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntAvailableRetryCountUpdateMessage -"<<"Forbidden value (" << this->questType << ") on element of TreasureHuntAvailableRetryCountUpdateMessage.questType.";
  }
  else
  {
    this->availableRetryCount = param1->readInt();
    return;
  }
}

TreasureHuntAvailableRetryCountUpdateMessage::TreasureHuntAvailableRetryCountUpdateMessage()
{
  m_type = MessageEnum::TREASUREHUNTAVAILABLERETRYCOUNTUPDATEMESSAGE;
}

