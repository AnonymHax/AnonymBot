#include "InventoryPresetSaveCustomMessage.h"

void InventoryPresetSaveCustomMessage::serialize(Writer *param1)
{
  this->serializeAs_InventoryPresetSaveCustomMessage(param1);
}

void InventoryPresetSaveCustomMessage::serializeAs_InventoryPresetSaveCustomMessage(Writer *param1)
{
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - InventoryPresetSaveCustomMessage -"<<"Forbidden value (" << this->presetId << ") on element presetId.";
  }
  else
  {
    param1->writeByte(this->presetId);
    if(this->symbolId < 0)
    {
      qDebug()<<"ERREUR - InventoryPresetSaveCustomMessage -"<<"Forbidden value (" << this->symbolId << ") on element symbolId.";
    }
    else
    {
      param1->writeByte(this->symbolId);
      param1->writeShort((short)this->itemsPositions.size());
      uint _loc2_ = 0;
      while(_loc2_ < this->itemsPositions.size())
      {
        param1->writeByte(this->itemsPositions[_loc2_]);
        _loc2_++;
      }
      param1->writeShort((short)this->itemsUids.size());
      uint _loc3_ = 0;
      while(_loc3_ < this->itemsUids.size())
      {
        if(this->itemsUids[_loc3_] < 0)
        {
          qDebug()<<"ERREUR - InventoryPresetSaveCustomMessage -"<<"Forbidden value (" << this->itemsUids[_loc3_] << ") on element 4 (starting at 1) of itemsUids.";
        }
        else
        {
          param1->writeVarInt((int)this->itemsUids[_loc3_]);
          _loc3_++;
          continue;
        }
      }
      return;
    }
  }
}

void InventoryPresetSaveCustomMessage::deserialize(Reader *param1)
{
  this->deserializeAs_InventoryPresetSaveCustomMessage(param1);
}

void InventoryPresetSaveCustomMessage::deserializeAs_InventoryPresetSaveCustomMessage(Reader *param1)
{
  uint _loc6_ = 0;
  uint _loc7_ = 0;
  this->presetId = param1->readByte();
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - InventoryPresetSaveCustomMessage -"<<"Forbidden value (" << this->presetId << ") on element of InventoryPresetSaveCustomMessage.presetId.";
  }
  else
  {
    this->symbolId = param1->readByte();
    if(this->symbolId < 0)
    {
      qDebug()<<"ERREUR - InventoryPresetSaveCustomMessage -"<<"Forbidden value (" << this->symbolId << ") on element of InventoryPresetSaveCustomMessage.symbolId.";
    }
    else
    {
      uint _loc2_ = param1->readUShort();
      uint _loc3_ = 0;
      while(_loc3_ < _loc2_)
      {
        _loc6_ = param1->readUByte();
        if(_loc6_ < 0 || _loc6_ > 255)
        {
          qDebug()<<"ERREUR - InventoryPresetSaveCustomMessage -"<<"Forbidden value (" << _loc6_ << ") on elements of itemsPositions.";
        }
        else
        {
          this->itemsPositions.append(_loc6_);
          _loc3_++;
          continue;
        }
      }
      uint _loc4_ = param1->readUShort();
      uint _loc5_ = 0;
      while(_loc5_ < _loc4_)
      {
        _loc7_ = param1->readVarUhInt();
        if(_loc7_ < 0)
        {
          qDebug()<<"ERREUR - InventoryPresetSaveCustomMessage -"<<"Forbidden value (" << _loc7_ << ") on elements of itemsUids.";
        }
        else
        {
          this->itemsUids.append(_loc7_);
          _loc5_++;
          continue;
        }
      }
      return;
    }
  }
}

InventoryPresetSaveCustomMessage::InventoryPresetSaveCustomMessage()
{
  m_type = MessageEnum::INVENTORYPRESETSAVECUSTOMMESSAGE;
}

