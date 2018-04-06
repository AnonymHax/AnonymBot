#include "TreasureHuntLegendaryRequestMessage.h"

void TreasureHuntLegendaryRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_TreasureHuntLegendaryRequestMessage(param1);
}

void TreasureHuntLegendaryRequestMessage::serializeAs_TreasureHuntLegendaryRequestMessage(Writer *param1)
{
  if(this->legendaryId < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntLegendaryRequestMessage -"<<"Forbidden value (" << this->legendaryId << ") on element legendaryId.";
  }
  else
  {
    param1->writeVarShort((int)this->legendaryId);
    return;
  }
}

void TreasureHuntLegendaryRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TreasureHuntLegendaryRequestMessage(param1);
}

void TreasureHuntLegendaryRequestMessage::deserializeAs_TreasureHuntLegendaryRequestMessage(Reader *param1)
{
  this->legendaryId = param1->readVarUhShort();
  if(this->legendaryId < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntLegendaryRequestMessage -"<<"Forbidden value (" << this->legendaryId << ") on element of TreasureHuntLegendaryRequestMessage.legendaryId.";
  }
  else
  {
    return;
  }
}

TreasureHuntLegendaryRequestMessage::TreasureHuntLegendaryRequestMessage()
{
  m_type = MessageEnum::TREASUREHUNTLEGENDARYREQUESTMESSAGE;
}

