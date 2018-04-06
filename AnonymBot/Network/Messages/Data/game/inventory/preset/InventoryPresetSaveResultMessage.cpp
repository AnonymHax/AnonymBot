#include "InventoryPresetSaveResultMessage.h"

void InventoryPresetSaveResultMessage::serialize(Writer *param1)
{
  this->serializeAs_InventoryPresetSaveResultMessage(param1);
}

void InventoryPresetSaveResultMessage::serializeAs_InventoryPresetSaveResultMessage(Writer *param1)
{
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - InventoryPresetSaveResultMessage -"<<"Forbidden value (" << this->presetId << ") on element presetId.";
  }
  else
  {
    param1->writeByte(this->presetId);
    param1->writeByte(this->code);
    return;
  }
}

void InventoryPresetSaveResultMessage::deserialize(Reader *param1)
{
  this->deserializeAs_InventoryPresetSaveResultMessage(param1);
}

void InventoryPresetSaveResultMessage::deserializeAs_InventoryPresetSaveResultMessage(Reader *param1)
{
  this->presetId = param1->readByte();
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - InventoryPresetSaveResultMessage -"<<"Forbidden value (" << this->presetId << ") on element of InventoryPresetSaveResultMessage.presetId.";
  }
  else
  {
    this->code = param1->readByte();
    if(this->code < 0)
    {
      qDebug()<<"ERREUR - InventoryPresetSaveResultMessage -"<<"Forbidden value (" << this->code << ") on element of InventoryPresetSaveResultMessage.code.";
    }
    else
    {
      return;
    }
  }
}

InventoryPresetSaveResultMessage::InventoryPresetSaveResultMessage()
{
  m_type = MessageEnum::INVENTORYPRESETSAVERESULTMESSAGE;
}

