#include "PresetItem.h"

void PresetItem::serialize(Writer *param1)
{
  this->serializeAs_PresetItem(param1);
}

void PresetItem::serializeAs_PresetItem(Writer *param1)
{
  param1->writeByte(this->position);
  if(this->objGid < 0)
  {
    qDebug()<<"ERREUR - PresetItem -"<<"Forbidden value (" << this->objGid << ") on element objGid.";
  }
  else
  {
    param1->writeVarShort((int)this->objGid);
    if(this->objUid < 0)
    {
      qDebug()<<"ERREUR - PresetItem -"<<"Forbidden value (" << this->objUid << ") on element objUid.";
    }
    else
    {
      param1->writeVarInt((int)this->objUid);
      return;
    }
  }
}

void PresetItem::deserialize(Reader *param1)
{
  this->deserializeAs_PresetItem(param1);
}

void PresetItem::deserializeAs_PresetItem(Reader *param1)
{
  this->position = param1->readUByte();
  if(this->position < 0 || this->position > 255)
  {
    qDebug()<<"ERREUR - PresetItem -"<<"Forbidden value (" << this->position << ") on element of PresetItem.position.";
  }
  else
  {
    this->objGid = param1->readVarUhShort();
    if(this->objGid < 0)
    {
      qDebug()<<"ERREUR - PresetItem -"<<"Forbidden value (" << this->objGid << ") on element of PresetItem.objGid.";
    }
    else
    {
      this->objUid = param1->readVarUhInt();
      if(this->objUid < 0)
      {
        qDebug()<<"ERREUR - PresetItem -"<<"Forbidden value (" << this->objUid << ") on element of PresetItem.objUid.";
      }
      else
      {
        return;
      }
    }
  }
}

PresetItem::PresetItem()
{
  m_types<<ClassEnum::PRESETITEM;
}

bool PresetItem::operator==(const PresetItem &compared)
{
  if(position == compared.position)
  if(objGid == compared.objGid)
  if(objUid == compared.objUid)
  return true;
  
  return false;
}

