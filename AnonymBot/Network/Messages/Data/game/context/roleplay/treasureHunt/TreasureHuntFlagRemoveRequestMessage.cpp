#include "TreasureHuntFlagRemoveRequestMessage.h"

void TreasureHuntFlagRemoveRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_TreasureHuntFlagRemoveRequestMessage(param1);
}

void TreasureHuntFlagRemoveRequestMessage::serializeAs_TreasureHuntFlagRemoveRequestMessage(Writer *param1)
{
  param1->writeByte(this->questType);
  if(this->index < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntFlagRemoveRequestMessage -"<<"Forbidden value (" << this->index << ") on element index.";
  }
  else
  {
    param1->writeByte(this->index);
    return;
  }
}

void TreasureHuntFlagRemoveRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TreasureHuntFlagRemoveRequestMessage(param1);
}

void TreasureHuntFlagRemoveRequestMessage::deserializeAs_TreasureHuntFlagRemoveRequestMessage(Reader *param1)
{
  this->questType = param1->readByte();
  if(this->questType < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntFlagRemoveRequestMessage -"<<"Forbidden value (" << this->questType << ") on element of TreasureHuntFlagRemoveRequestMessage.questType.";
  }
  else
  {
    this->index = param1->readByte();
    if(this->index < 0)
    {
      qDebug()<<"ERREUR - TreasureHuntFlagRemoveRequestMessage -"<<"Forbidden value (" << this->index << ") on element of TreasureHuntFlagRemoveRequestMessage.index.";
    }
    else
    {
      return;
    }
  }
}

TreasureHuntFlagRemoveRequestMessage::TreasureHuntFlagRemoveRequestMessage()
{
  m_type = MessageEnum::TREASUREHUNTFLAGREMOVEREQUESTMESSAGE;
}

