#include "InventoryPresetSaveMessage.h"

void InventoryPresetSaveMessage::serialize(Writer *param1)
{
  this->serializeAs_InventoryPresetSaveMessage(param1);
}

void InventoryPresetSaveMessage::serializeAs_InventoryPresetSaveMessage(Writer *param1)
{
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - InventoryPresetSaveMessage -"<<"Forbidden value (" << this->presetId << ") on element presetId.";
  }
  else
  {
    param1->writeByte(this->presetId);
    if(this->symbolId < 0)
    {
      qDebug()<<"ERREUR - InventoryPresetSaveMessage -"<<"Forbidden value (" << this->symbolId << ") on element symbolId.";
    }
    else
    {
      param1->writeByte(this->symbolId);
      param1->writeBool(this->saveEquipment);
      return;
    }
  }
}

void InventoryPresetSaveMessage::deserialize(Reader *param1)
{
  this->deserializeAs_InventoryPresetSaveMessage(param1);
}

void InventoryPresetSaveMessage::deserializeAs_InventoryPresetSaveMessage(Reader *param1)
{
  this->presetId = param1->readByte();
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - InventoryPresetSaveMessage -"<<"Forbidden value (" << this->presetId << ") on element of InventoryPresetSaveMessage.presetId.";
  }
  else
  {
    this->symbolId = param1->readByte();
    if(this->symbolId < 0)
    {
      qDebug()<<"ERREUR - InventoryPresetSaveMessage -"<<"Forbidden value (" << this->symbolId << ") on element of InventoryPresetSaveMessage.symbolId.";
    }
    else
    {
      this->saveEquipment = param1->readBool();
      return;
    }
  }
}

InventoryPresetSaveMessage::InventoryPresetSaveMessage()
{
  m_type = MessageEnum::INVENTORYPRESETSAVEMESSAGE;
}

