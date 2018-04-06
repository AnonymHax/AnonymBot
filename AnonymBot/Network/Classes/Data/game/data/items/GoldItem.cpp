#include "GoldItem.h"

void GoldItem::serialize(Writer *param1)
{
  this->serializeAs_GoldItem(param1);
}

void GoldItem::serializeAs_GoldItem(Writer *param1)
{
  Item::serializeAs_Item(param1);
  if(this->sum < 0)
  {
    qDebug()<<"ERREUR - GoldItem -"<<"Forbidden value (" << this->sum << ") on element sum.";
  }
  else
  {
    param1->writeVarInt((int)this->sum);
    return;
  }
}

void GoldItem::deserialize(Reader *param1)
{
  this->deserializeAs_GoldItem(param1);
}

void GoldItem::deserializeAs_GoldItem(Reader *param1)
{
  Item::deserialize(param1);
  this->sum = param1->readVarUhInt();
  if(this->sum < 0)
  {
    qDebug()<<"ERREUR - GoldItem -"<<"Forbidden value (" << this->sum << ") on element of GoldItem.sum.";
  }
  else
  {
    return;
  }
}

GoldItem::GoldItem()
{
  m_types<<ClassEnum::GOLDITEM;
}

bool GoldItem::operator==(const GoldItem &compared)
{
  if(sum == compared.sum)
  return true;
  
  return false;
}

