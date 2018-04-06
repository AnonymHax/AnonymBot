#include "InventoryPresetUpdateMessage.h"

void InventoryPresetUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_InventoryPresetUpdateMessage(param1);
}

void InventoryPresetUpdateMessage::serializeAs_InventoryPresetUpdateMessage(Writer *param1)
{
  this->preset.serializeAs_Preset(param1);
}

void InventoryPresetUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_InventoryPresetUpdateMessage(param1);
}

void InventoryPresetUpdateMessage::deserializeAs_InventoryPresetUpdateMessage(Reader *param1)
{
  this->preset = Preset();
  this->preset.deserialize(param1);
}

InventoryPresetUpdateMessage::InventoryPresetUpdateMessage()
{
  m_type = MessageEnum::INVENTORYPRESETUPDATEMESSAGE;
}

