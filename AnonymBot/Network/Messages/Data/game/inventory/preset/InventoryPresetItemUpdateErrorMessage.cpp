#include "InventoryPresetItemUpdateErrorMessage.h"

void InventoryPresetItemUpdateErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_InventoryPresetItemUpdateErrorMessage(param1);
}

void InventoryPresetItemUpdateErrorMessage::serializeAs_InventoryPresetItemUpdateErrorMessage(Writer *param1)
{
  param1->writeByte(this->code);
}

void InventoryPresetItemUpdateErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_InventoryPresetItemUpdateErrorMessage(param1);
}

void InventoryPresetItemUpdateErrorMessage::deserializeAs_InventoryPresetItemUpdateErrorMessage(Reader *param1)
{
  this->code = param1->readByte();
  if(this->code < 0)
  {
    qDebug()<<"ERREUR - InventoryPresetItemUpdateErrorMessage -"<<"Forbidden value (" << this->code << ") on element of InventoryPresetItemUpdateErrorMessage.code.";
  }
  else
  {
    return;
  }
}

InventoryPresetItemUpdateErrorMessage::InventoryPresetItemUpdateErrorMessage()
{
  m_type = MessageEnum::INVENTORYPRESETITEMUPDATEERRORMESSAGE;
}

