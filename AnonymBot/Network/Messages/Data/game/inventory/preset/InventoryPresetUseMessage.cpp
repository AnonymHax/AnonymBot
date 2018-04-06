#include "InventoryPresetUseMessage.h"

void InventoryPresetUseMessage::serialize(Writer *param1)
{
  this->serializeAs_InventoryPresetUseMessage(param1);
}

void InventoryPresetUseMessage::serializeAs_InventoryPresetUseMessage(Writer *param1)
{
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - InventoryPresetUseMessage -"<<"Forbidden value (" << this->presetId << ") on element presetId.";
  }
  else
  {
    param1->writeByte(this->presetId);
    return;
  }
}

void InventoryPresetUseMessage::deserialize(Reader *param1)
{
  this->deserializeAs_InventoryPresetUseMessage(param1);
}

void InventoryPresetUseMessage::deserializeAs_InventoryPresetUseMessage(Reader *param1)
{
  this->presetId = param1->readByte();
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - InventoryPresetUseMessage -"<<"Forbidden value (" << this->presetId << ") on element of InventoryPresetUseMessage.presetId.";
  }
  else
  {
    return;
  }
}

InventoryPresetUseMessage::InventoryPresetUseMessage()
{
  m_type = MessageEnum::INVENTORYPRESETUSEMESSAGE;
}

