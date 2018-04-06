#include "TreasureHuntFinishedMessage.h"

void TreasureHuntFinishedMessage::serialize(Writer *param1)
{
  this->serializeAs_TreasureHuntFinishedMessage(param1);
}

void TreasureHuntFinishedMessage::serializeAs_TreasureHuntFinishedMessage(Writer *param1)
{
  param1->writeByte(this->questType);
}

void TreasureHuntFinishedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TreasureHuntFinishedMessage(param1);
}

void TreasureHuntFinishedMessage::deserializeAs_TreasureHuntFinishedMessage(Reader *param1)
{
  this->questType = param1->readByte();
  if(this->questType < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntFinishedMessage -"<<"Forbidden value (" << this->questType << ") on element of TreasureHuntFinishedMessage.questType.";
  }
  else
  {
    return;
  }
}

TreasureHuntFinishedMessage::TreasureHuntFinishedMessage()
{
  m_type = MessageEnum::TREASUREHUNTFINISHEDMESSAGE;
}

