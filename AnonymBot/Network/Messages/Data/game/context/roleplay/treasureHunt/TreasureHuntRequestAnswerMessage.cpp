#include "TreasureHuntRequestAnswerMessage.h"

void TreasureHuntRequestAnswerMessage::serialize(Writer *param1)
{
  this->serializeAs_TreasureHuntRequestAnswerMessage(param1);
}

void TreasureHuntRequestAnswerMessage::serializeAs_TreasureHuntRequestAnswerMessage(Writer *param1)
{
  param1->writeByte(this->questType);
  param1->writeByte(this->result);
}

void TreasureHuntRequestAnswerMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TreasureHuntRequestAnswerMessage(param1);
}

void TreasureHuntRequestAnswerMessage::deserializeAs_TreasureHuntRequestAnswerMessage(Reader *param1)
{
  this->questType = param1->readByte();
  if(this->questType < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntRequestAnswerMessage -"<<"Forbidden value (" << this->questType << ") on element of TreasureHuntRequestAnswerMessage.questType.";
  }
  else
  {
    this->result = param1->readByte();
    if(this->result < 0)
    {
      qDebug()<<"ERREUR - TreasureHuntRequestAnswerMessage -"<<"Forbidden value (" << this->result << ") on element of TreasureHuntRequestAnswerMessage.result.";
    }
    else
    {
      return;
    }
  }
}

TreasureHuntRequestAnswerMessage::TreasureHuntRequestAnswerMessage()
{
  m_type = MessageEnum::TREASUREHUNTREQUESTANSWERMESSAGE;
}

