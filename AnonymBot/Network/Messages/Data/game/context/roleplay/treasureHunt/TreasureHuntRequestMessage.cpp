#include "TreasureHuntRequestMessage.h"

void TreasureHuntRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_TreasureHuntRequestMessage(param1);
}

void TreasureHuntRequestMessage::serializeAs_TreasureHuntRequestMessage(Writer *param1)
{
  if(this->questLevel < 1 || this->questLevel > 206)
  {
    qDebug()<<"ERREUR - TreasureHuntRequestMessage -"<<"Forbidden value (" << this->questLevel << ") on element questLevel.";
  }
  else
  {
    param1->writeByte(this->questLevel);
    param1->writeByte(this->questType);
    return;
  }
}

void TreasureHuntRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TreasureHuntRequestMessage(param1);
}

void TreasureHuntRequestMessage::deserializeAs_TreasureHuntRequestMessage(Reader *param1)
{
  this->questLevel = param1->readUByte();
  if(this->questLevel < 1 || this->questLevel > 206)
  {
    qDebug()<<"ERREUR - TreasureHuntRequestMessage -"<<"Forbidden value (" << this->questLevel << ") on element of TreasureHuntRequestMessage.questLevel.";
  }
  else
  {
    this->questType = param1->readByte();
    if(this->questType < 0)
    {
      qDebug()<<"ERREUR - TreasureHuntRequestMessage -"<<"Forbidden value (" << this->questType << ") on element of TreasureHuntRequestMessage.questType.";
    }
    else
    {
      return;
    }
  }
}

TreasureHuntRequestMessage::TreasureHuntRequestMessage()
{
  m_type = MessageEnum::TREASUREHUNTREQUESTMESSAGE;
}

