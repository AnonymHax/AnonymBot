#include "TreasureHuntFlagRequestMessage.h"

void TreasureHuntFlagRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_TreasureHuntFlagRequestMessage(param1);
}

void TreasureHuntFlagRequestMessage::serializeAs_TreasureHuntFlagRequestMessage(Writer *param1)
{
  param1->writeByte(this->questType);
  if(this->index < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntFlagRequestMessage -"<<"Forbidden value (" << this->index << ") on element index.";
  }
  else
  {
    param1->writeByte(this->index);
    return;
  }
}

void TreasureHuntFlagRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TreasureHuntFlagRequestMessage(param1);
}

void TreasureHuntFlagRequestMessage::deserializeAs_TreasureHuntFlagRequestMessage(Reader *param1)
{
  this->questType = param1->readByte();
  if(this->questType < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntFlagRequestMessage -"<<"Forbidden value (" << this->questType << ") on element of TreasureHuntFlagRequestMessage.questType.";
  }
  else
  {
    this->index = param1->readByte();
    if(this->index < 0)
    {
      qDebug()<<"ERREUR - TreasureHuntFlagRequestMessage -"<<"Forbidden value (" << this->index << ") on element of TreasureHuntFlagRequestMessage.index.";
    }
    else
    {
      return;
    }
  }
}

TreasureHuntFlagRequestMessage::TreasureHuntFlagRequestMessage()
{
  m_type = MessageEnum::TREASUREHUNTFLAGREQUESTMESSAGE;
}

