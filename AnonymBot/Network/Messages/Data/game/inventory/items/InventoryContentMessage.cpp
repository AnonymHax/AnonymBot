#include "InventoryContentMessage.h"

void InventoryContentMessage::serialize(Writer *param1)
{
  this->serializeAs_InventoryContentMessage(param1);
}

void InventoryContentMessage::serializeAs_InventoryContentMessage(Writer *param1)
{
  param1->writeShort((short)this->objects.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->objects.size())
  {
    qSharedPointerCast<ObjectItem>(this->objects[_loc2_])->serializeAs_ObjectItem(param1);
    _loc2_++;
  }
  if(this->kamas < 0)
  {
    qDebug()<<"ERREUR - InventoryContentMessage -"<<"Forbidden value (" << this->kamas << ") on element kamas.";
  }
  else
  {
    param1->writeVarInt((int)this->kamas);
    return;
  }
}

void InventoryContentMessage::deserialize(Reader *param1)
{
  this->deserializeAs_InventoryContentMessage(param1);
}

void InventoryContentMessage::deserializeAs_InventoryContentMessage(Reader *param1)
{
  QSharedPointer<ObjectItem> _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = QSharedPointer<ObjectItem>(new ObjectItem() );
    _loc4_->deserialize(param1);
    this->objects.append(_loc4_);
    _loc3_++;
  }
  this->kamas = param1->readVarUhInt();
  if(this->kamas < 0)
  {
    qDebug()<<"ERREUR - InventoryContentMessage -"<<"Forbidden value (" << this->kamas << ") on element of InventoryContentMessage.kamas.";
  }
  else
  {
    return;
  }
}

InventoryContentMessage::InventoryContentMessage()
{
  m_type = MessageEnum::INVENTORYCONTENTMESSAGE;
}

