#include "InventoryPresetItemUpdateMessage.h"

void InventoryPresetItemUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_InventoryPresetItemUpdateMessage(param1);
}

void InventoryPresetItemUpdateMessage::serializeAs_InventoryPresetItemUpdateMessage(Writer *param1)
{
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - InventoryPresetItemUpdateMessage -"<<"Forbidden value (" << this->presetId << ") on element presetId.";
  }
  else
  {
    param1->writeByte(this->presetId);
    this->presetItem.serializeAs_PresetItem(param1);
    return;
  }
}

void InventoryPresetItemUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_InventoryPresetItemUpdateMessage(param1);
}

void InventoryPresetItemUpdateMessage::deserializeAs_InventoryPresetItemUpdateMessage(Reader *param1)
{
  this->presetId = param1->readByte();
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - InventoryPresetItemUpdateMessage -"<<"Forbidden value (" << this->presetId << ") on element of InventoryPresetItemUpdateMessage.presetId.";
  }
  else
  {
    this->presetItem = PresetItem();
    this->presetItem.deserialize(param1);
    return;
  }
}

InventoryPresetItemUpdateMessage::InventoryPresetItemUpdateMessage()
{
  m_type = MessageEnum::INVENTORYPRESETITEMUPDATEMESSAGE;
}

