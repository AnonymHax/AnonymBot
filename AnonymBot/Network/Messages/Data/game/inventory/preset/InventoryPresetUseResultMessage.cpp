#include "InventoryPresetUseResultMessage.h"

void InventoryPresetUseResultMessage::serialize(Writer *param1)
{
  this->serializeAs_InventoryPresetUseResultMessage(param1);
}

void InventoryPresetUseResultMessage::serializeAs_InventoryPresetUseResultMessage(Writer *param1)
{
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - InventoryPresetUseResultMessage -"<<"Forbidden value (" << this->presetId << ") on element presetId.";
  }
  else
  {
    param1->writeByte(this->presetId);
    param1->writeByte(this->code);
    param1->writeShort((short)this->unlinkedPosition.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->unlinkedPosition.size())
    {
      param1->writeByte(this->unlinkedPosition[_loc2_]);
      _loc2_++;
    }
    return;
  }
}

void InventoryPresetUseResultMessage::deserialize(Reader *param1)
{
  this->deserializeAs_InventoryPresetUseResultMessage(param1);
}

void InventoryPresetUseResultMessage::deserializeAs_InventoryPresetUseResultMessage(Reader *param1)
{
  uint _loc4_ = 0;
  this->presetId = param1->readByte();
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - InventoryPresetUseResultMessage -"<<"Forbidden value (" << this->presetId << ") on element of InventoryPresetUseResultMessage.presetId.";
  }
  else
  {
    this->code = param1->readByte();
    if(this->code < 0)
    {
      qDebug()<<"ERREUR - InventoryPresetUseResultMessage -"<<"Forbidden value (" << this->code << ") on element of InventoryPresetUseResultMessage.code.";
    }
    else
    {
      uint _loc2_ = param1->readUShort();
      uint _loc3_ = 0;
      while(_loc3_ < _loc2_)
      {
        _loc4_ = param1->readUByte();
        if(_loc4_ < 0 || _loc4_ > 255)
        {
          qDebug()<<"ERREUR - InventoryPresetUseResultMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of unlinkedPosition.";
        }
        else
        {
          this->unlinkedPosition.append(_loc4_);
          _loc3_++;
          continue;
        }
      }
      return;
    }
  }
}

InventoryPresetUseResultMessage::InventoryPresetUseResultMessage()
{
  m_type = MessageEnum::INVENTORYPRESETUSERESULTMESSAGE;
}

