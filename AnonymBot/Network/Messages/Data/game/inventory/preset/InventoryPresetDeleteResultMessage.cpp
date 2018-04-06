#include "InventoryPresetDeleteResultMessage.h"

void InventoryPresetDeleteResultMessage::serialize(Writer *param1)
{
  this->serializeAs_InventoryPresetDeleteResultMessage(param1);
}

void InventoryPresetDeleteResultMessage::serializeAs_InventoryPresetDeleteResultMessage(Writer *param1)
{
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - InventoryPresetDeleteResultMessage -"<<"Forbidden value (" << this->presetId << ") on element presetId.";
  }
  else
  {
    param1->writeByte(this->presetId);
    param1->writeByte(this->code);
    return;
  }
}

void InventoryPresetDeleteResultMessage::deserialize(Reader *param1)
{
  this->deserializeAs_InventoryPresetDeleteResultMessage(param1);
}

void InventoryPresetDeleteResultMessage::deserializeAs_InventoryPresetDeleteResultMessage(Reader *param1)
{
  this->presetId = param1->readByte();
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - InventoryPresetDeleteResultMessage -"<<"Forbidden value (" << this->presetId << ") on element of InventoryPresetDeleteResultMessage.presetId.";
  }
  else
  {
    this->code = param1->readByte();
    if(this->code < 0)
    {
      qDebug()<<"ERREUR - InventoryPresetDeleteResultMessage -"<<"Forbidden value (" << this->code << ") on element of InventoryPresetDeleteResultMessage.code.";
    }
    else
    {
      return;
    }
  }
}

InventoryPresetDeleteResultMessage::InventoryPresetDeleteResultMessage()
{
  m_type = MessageEnum::INVENTORYPRESETDELETERESULTMESSAGE;
}

