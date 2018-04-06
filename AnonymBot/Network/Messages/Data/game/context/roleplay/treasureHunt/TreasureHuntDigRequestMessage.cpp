#include "TreasureHuntDigRequestMessage.h"

void TreasureHuntDigRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_TreasureHuntDigRequestMessage(param1);
}

void TreasureHuntDigRequestMessage::serializeAs_TreasureHuntDigRequestMessage(Writer *param1)
{
  param1->writeByte(this->questType);
}

void TreasureHuntDigRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TreasureHuntDigRequestMessage(param1);
}

void TreasureHuntDigRequestMessage::deserializeAs_TreasureHuntDigRequestMessage(Reader *param1)
{
  this->questType = param1->readByte();
  if(this->questType < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntDigRequestMessage -"<<"Forbidden value (" << this->questType << ") on element of TreasureHuntDigRequestMessage.questType.";
  }
  else
  {
    return;
  }
}

TreasureHuntDigRequestMessage::TreasureHuntDigRequestMessage()
{
  m_type = MessageEnum::TREASUREHUNTDIGREQUESTMESSAGE;
}

