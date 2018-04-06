#include "InventoryPresetItemUpdateRequestMessage.h"

void InventoryPresetItemUpdateRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_InventoryPresetItemUpdateRequestMessage(param1);
}

void InventoryPresetItemUpdateRequestMessage::serializeAs_InventoryPresetItemUpdateRequestMessage(Writer *param1)
{
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - InventoryPresetItemUpdateRequestMessage -"<<"Forbidden value (" << this->presetId << ") on element presetId.";
  }
  else
  {
    param1->writeByte(this->presetId);
    param1->writeByte(this->position);
    if(this->objUid < 0)
    {
      qDebug()<<"ERREUR - InventoryPresetItemUpdateRequestMessage -"<<"Forbidden value (" << this->objUid << ") on element objUid.";
    }
    else
    {
      param1->writeVarInt((int)this->objUid);
      return;
    }
  }
}

void InventoryPresetItemUpdateRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_InventoryPresetItemUpdateRequestMessage(param1);
}

void InventoryPresetItemUpdateRequestMessage::deserializeAs_InventoryPresetItemUpdateRequestMessage(Reader *param1)
{
  this->presetId = param1->readByte();
  if(this->presetId < 0)
  {
    qDebug()<<"ERREUR - InventoryPresetItemUpdateRequestMessage -"<<"Forbidden value (" << this->presetId << ") on element of InventoryPresetItemUpdateRequestMessage.presetId.";
  }
  else
  {
    this->position = param1->readUByte();
    if(this->position < 0 || this->position > 255)
    {
      qDebug()<<"ERREUR - InventoryPresetItemUpdateRequestMessage -"<<"Forbidden value (" << this->position << ") on element of InventoryPresetItemUpdateRequestMessage.position.";
    }
    else
    {
      this->objUid = param1->readVarUhInt();
      if(this->objUid < 0)
      {
        qDebug()<<"ERREUR - InventoryPresetItemUpdateRequestMessage -"<<"Forbidden value (" << this->objUid << ") on element of InventoryPresetItemUpdateRequestMessage.objUid.";
      }
      else
      {
        return;
      }
    }
  }
}

InventoryPresetItemUpdateRequestMessage::InventoryPresetItemUpdateRequestMessage()
{
  m_type = MessageEnum::INVENTORYPRESETITEMUPDATEREQUESTMESSAGE;
}

