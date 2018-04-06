#include "InventoryContentAndPresetMessage.h"

void InventoryContentAndPresetMessage::serialize(Writer *param1)
{
  this->serializeAs_InventoryContentAndPresetMessage(param1);
}

void InventoryContentAndPresetMessage::serializeAs_InventoryContentAndPresetMessage(Writer *param1)
{
  InventoryContentMessage::serializeAs_InventoryContentMessage(param1);
  param1->writeShort((short)this->presets.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->presets.size())
  {
    (this->presets[_loc2_]).serializeAs_Preset(param1);
    _loc2_++;
  }
  param1->writeShort((short)this->idolsPresets.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->idolsPresets.size())
  {
    (this->idolsPresets[_loc3_]).serializeAs_IdolsPreset(param1);
    _loc3_++;
  }
}

void InventoryContentAndPresetMessage::deserialize(Reader *param1)
{
  this->deserializeAs_InventoryContentAndPresetMessage(param1);
}

void InventoryContentAndPresetMessage::deserializeAs_InventoryContentAndPresetMessage(Reader *param1)
{
  Preset _loc6_ ;
  IdolsPreset _loc7_ ;
  InventoryContentMessage::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc6_ = Preset();
    _loc6_.deserialize(param1);
    this->presets.append(_loc6_);
    _loc3_++;
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc7_ = IdolsPreset();
    _loc7_.deserialize(param1);
    this->idolsPresets.append(_loc7_);
    _loc5_++;
  }
}

InventoryContentAndPresetMessage::InventoryContentAndPresetMessage()
{
  m_type = MessageEnum::INVENTORYCONTENTANDPRESETMESSAGE;
}

