#include "InventoryWeightMessage.h"

void InventoryWeightMessage::serialize(Writer *param1)
{
  this->serializeAs_InventoryWeightMessage(param1);
}

void InventoryWeightMessage::serializeAs_InventoryWeightMessage(Writer *param1)
{
  if(this->weight < 0)
  {
    qDebug()<<"ERREUR - InventoryWeightMessage -"<<"Forbidden value (" << this->weight << ") on element weight.";
  }
  else
  {
    param1->writeVarInt((int)this->weight);
    if(this->weightMax < 0)
    {
      qDebug()<<"ERREUR - InventoryWeightMessage -"<<"Forbidden value (" << this->weightMax << ") on element weightMax.";
    }
    else
    {
      param1->writeVarInt((int)this->weightMax);
      return;
    }
  }
}

void InventoryWeightMessage::deserialize(Reader *param1)
{
  this->deserializeAs_InventoryWeightMessage(param1);
}

void InventoryWeightMessage::deserializeAs_InventoryWeightMessage(Reader *param1)
{
  this->weight = param1->readVarUhInt();
  if(this->weight < 0)
  {
    qDebug()<<"ERREUR - InventoryWeightMessage -"<<"Forbidden value (" << this->weight << ") on element of InventoryWeightMessage.weight.";
  }
  else
  {
    this->weightMax = param1->readVarUhInt();
    if(this->weightMax < 0)
    {
      qDebug()<<"ERREUR - InventoryWeightMessage -"<<"Forbidden value (" << this->weightMax << ") on element of InventoryWeightMessage.weightMax.";
    }
    else
    {
      return;
    }
  }
}

InventoryWeightMessage::InventoryWeightMessage()
{
  m_type = MessageEnum::INVENTORYWEIGHTMESSAGE;
}

