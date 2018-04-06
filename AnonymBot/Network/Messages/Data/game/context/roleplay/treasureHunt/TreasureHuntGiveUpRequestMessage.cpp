#include "TreasureHuntGiveUpRequestMessage.h"

void TreasureHuntGiveUpRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_TreasureHuntGiveUpRequestMessage(param1);
}

void TreasureHuntGiveUpRequestMessage::serializeAs_TreasureHuntGiveUpRequestMessage(Writer *param1)
{
  param1->writeByte(this->questType);
}

void TreasureHuntGiveUpRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TreasureHuntGiveUpRequestMessage(param1);
}

void TreasureHuntGiveUpRequestMessage::deserializeAs_TreasureHuntGiveUpRequestMessage(Reader *param1)
{
  this->questType = param1->readByte();
  if(this->questType < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntGiveUpRequestMessage -"<<"Forbidden value (" << this->questType << ") on element of TreasureHuntGiveUpRequestMessage.questType.";
  }
  else
  {
    return;
  }
}

TreasureHuntGiveUpRequestMessage::TreasureHuntGiveUpRequestMessage()
{
  m_type = MessageEnum::TREASUREHUNTGIVEUPREQUESTMESSAGE;
}

