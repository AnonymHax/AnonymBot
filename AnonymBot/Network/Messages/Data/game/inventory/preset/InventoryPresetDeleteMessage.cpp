#include "InventoryPresetDeleteMessage.h"

void InventoryPresetDeleteMessage::serialize(Writer *param1)
{
  this->serializeAs_InventoryPresetDeleteMessage(param1);
}

void InventoryPresetDeleteMessage::serializeAs_InventoryPresetDeleteMessage(Writer *param1)
{
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - InventoryPresetDeleteMessage -"<<"Forbidden value (" << this->presetId << ") on element presetId.";
  }
  else
  {
    param1->writeByte(this->presetId);
    return;
  }
}

void InventoryPresetDeleteMessage::deserialize(Reader *param1)
{
  this->deserializeAs_InventoryPresetDeleteMessage(param1);
}

void InventoryPresetDeleteMessage::deserializeAs_InventoryPresetDeleteMessage(Reader *param1)
{
  this->presetId = param1->readByte();
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - InventoryPresetDeleteMessage -"<<"Forbidden value (" << this->presetId << ") on element of InventoryPresetDeleteMessage.presetId.";
  }
  else
  {
    return;
  }
}

InventoryPresetDeleteMessage::InventoryPresetDeleteMessage()
{
  m_type = MessageEnum::INVENTORYPRESETDELETEMESSAGE;
}

