#include "TreasureHuntDigRequestAnswerMessage.h"

void TreasureHuntDigRequestAnswerMessage::serialize(Writer *param1)
{
  this->serializeAs_TreasureHuntDigRequestAnswerMessage(param1);
}

void TreasureHuntDigRequestAnswerMessage::serializeAs_TreasureHuntDigRequestAnswerMessage(Writer *param1)
{
  param1->writeByte(this->questType);
  param1->writeByte(this->result);
}

void TreasureHuntDigRequestAnswerMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TreasureHuntDigRequestAnswerMessage(param1);
}

void TreasureHuntDigRequestAnswerMessage::deserializeAs_TreasureHuntDigRequestAnswerMessage(Reader *param1)
{
  this->questType = param1->readByte();
  if(this->questType < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntDigRequestAnswerMessage -"<<"Forbidden value (" << this->questType << ") on element of TreasureHuntDigRequestAnswerMessage.questType.";
  }
  else
  {
    this->result = param1->readByte();
    if(this->result < 0)
    {
      qDebug()<<"ERREUR - TreasureHuntDigRequestAnswerMessage -"<<"Forbidden value (" << this->result << ") on element of TreasureHuntDigRequestAnswerMessage.result.";
    }
    else
    {
      return;
    }
  }
}

TreasureHuntDigRequestAnswerMessage::TreasureHuntDigRequestAnswerMessage()
{
  m_type = MessageEnum::TREASUREHUNTDIGREQUESTANSWERMESSAGE;
}

