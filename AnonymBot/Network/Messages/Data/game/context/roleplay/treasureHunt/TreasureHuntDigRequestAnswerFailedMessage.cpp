#include "TreasureHuntDigRequestAnswerFailedMessage.h"

void TreasureHuntDigRequestAnswerFailedMessage::serialize(Writer *param1)
{
  this->serializeAs_TreasureHuntDigRequestAnswerFailedMessage(param1);
}

void TreasureHuntDigRequestAnswerFailedMessage::serializeAs_TreasureHuntDigRequestAnswerFailedMessage(Writer *param1)
{
  TreasureHuntDigRequestAnswerMessage::serializeAs_TreasureHuntDigRequestAnswerMessage(param1);
  if(this->wrongFlagCount < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntDigRequestAnswerFailedMessage -"<<"Forbidden value (" << this->wrongFlagCount << ") on element wrongFlagCount.";
  }
  else
  {
    param1->writeByte(this->wrongFlagCount);
    return;
  }
}

void TreasureHuntDigRequestAnswerFailedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TreasureHuntDigRequestAnswerFailedMessage(param1);
}

void TreasureHuntDigRequestAnswerFailedMessage::deserializeAs_TreasureHuntDigRequestAnswerFailedMessage(Reader *param1)
{
  TreasureHuntDigRequestAnswerMessage::deserialize(param1);
  this->wrongFlagCount = param1->readByte();
  if(this->wrongFlagCount < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntDigRequestAnswerFailedMessage -"<<"Forbidden value (" << this->wrongFlagCount << ") on element of TreasureHuntDigRequestAnswerFailedMessage.wrongFlagCount.";
  }
  else
  {
    return;
  }
}

TreasureHuntDigRequestAnswerFailedMessage::TreasureHuntDigRequestAnswerFailedMessage()
{
  m_type = MessageEnum::TREASUREHUNTDIGREQUESTANSWERFAILEDMESSAGE;
}

