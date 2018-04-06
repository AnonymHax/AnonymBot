#include "TreasureHuntFlagRequestAnswerMessage.h"

void TreasureHuntFlagRequestAnswerMessage::serialize(Writer *param1)
{
  this->serializeAs_TreasureHuntFlagRequestAnswerMessage(param1);
}

void TreasureHuntFlagRequestAnswerMessage::serializeAs_TreasureHuntFlagRequestAnswerMessage(Writer *param1)
{
  param1->writeByte(this->questType);
  param1->writeByte(this->result);
  if(this->index < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntFlagRequestAnswerMessage -"<<"Forbidden value (" << this->index << ") on element index.";
  }
  else
  {
    param1->writeByte(this->index);
    return;
  }
}

void TreasureHuntFlagRequestAnswerMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TreasureHuntFlagRequestAnswerMessage(param1);
}

void TreasureHuntFlagRequestAnswerMessage::deserializeAs_TreasureHuntFlagRequestAnswerMessage(Reader *param1)
{
  this->questType = param1->readByte();
  if(this->questType < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntFlagRequestAnswerMessage -"<<"Forbidden value (" << this->questType << ") on element of TreasureHuntFlagRequestAnswerMessage.questType.";
  }
  else
  {
    this->result = param1->readByte();
    if(this->result < 0)
    {
      qDebug()<<"ERREUR - TreasureHuntFlagRequestAnswerMessage -"<<"Forbidden value (" << this->result << ") on element of TreasureHuntFlagRequestAnswerMessage.result.";
    }
    else
    {
      this->index = param1->readByte();
      if(this->index < 0)
      {
        qDebug()<<"ERREUR - TreasureHuntFlagRequestAnswerMessage -"<<"Forbidden value (" << this->index << ") on element of TreasureHuntFlagRequestAnswerMessage.index.";
      }
      else
      {
        return;
      }
    }
  }
}

TreasureHuntFlagRequestAnswerMessage::TreasureHuntFlagRequestAnswerMessage()
{
  m_type = MessageEnum::TREASUREHUNTFLAGREQUESTANSWERMESSAGE;
}

