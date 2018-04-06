#include "TreasureHuntShowLegendaryUIMessage.h"

void TreasureHuntShowLegendaryUIMessage::serialize(Writer *param1)
{
  this->serializeAs_TreasureHuntShowLegendaryUIMessage(param1);
}

void TreasureHuntShowLegendaryUIMessage::serializeAs_TreasureHuntShowLegendaryUIMessage(Writer *param1)
{
  param1->writeShort((short)this->availableLegendaryIds.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->availableLegendaryIds.size())
  {
    if(this->availableLegendaryIds[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - TreasureHuntShowLegendaryUIMessage -"<<"Forbidden value (" << this->availableLegendaryIds[_loc2_] << ") on element 1 (starting at 1) of availableLegendaryIds.";
    }
    else
    {
      param1->writeVarShort((int)this->availableLegendaryIds[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void TreasureHuntShowLegendaryUIMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TreasureHuntShowLegendaryUIMessage(param1);
}

void TreasureHuntShowLegendaryUIMessage::deserializeAs_TreasureHuntShowLegendaryUIMessage(Reader *param1)
{
  uint _loc4_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readVarUhShort();
    if(_loc4_ < 0)
    {
      qDebug()<<"ERREUR - TreasureHuntShowLegendaryUIMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of availableLegendaryIds.";
    }
    else
    {
      this->availableLegendaryIds.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

TreasureHuntShowLegendaryUIMessage::TreasureHuntShowLegendaryUIMessage()
{
  m_type = MessageEnum::TREASUREHUNTSHOWLEGENDARYUIMESSAGE;
}

