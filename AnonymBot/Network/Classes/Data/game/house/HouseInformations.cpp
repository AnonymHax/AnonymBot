#include "HouseInformations.h"

void HouseInformations::serialize(Writer *param1)
{
  this->serializeAs_HouseInformations(param1);
}

void HouseInformations::serializeAs_HouseInformations(Writer *param1)
{
  uint _loc2_ = 0;
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->isOnSale);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->isSaleLocked);
  param1->writeByte(_loc2_);
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseInformations -"<<"Forbidden value (" << this->houseId << ") on element houseId.";
  }
  else
  {
    param1->writeVarInt((int)this->houseId);
    param1->writeShort((short)this->doorsOnMap.size());
    uint _loc3_ = 0;
    while(_loc3_ < this->doorsOnMap.size())
    {
      if(this->doorsOnMap[_loc3_] < 0)
      {
        qDebug()<<"ERREUR - HouseInformations -"<<"Forbidden value (" << this->doorsOnMap[_loc3_] << ") on element 2 (starting at 1) of doorsOnMap.";
      }
      else
      {
        param1->writeInt((int)this->doorsOnMap[_loc3_]);
        _loc3_++;
        continue;
      }
    }
    param1->writeUTF(this->ownerName);
    if(this->modelId < 0)
    {
      qDebug()<<"ERREUR - HouseInformations -"<<"Forbidden value (" << this->modelId << ") on element modelId.";
    }
    else
    {
      param1->writeVarShort((int)this->modelId);
      return;
    }
  }
}

void HouseInformations::deserialize(Reader *param1)
{
  this->deserializeAs_HouseInformations(param1);
}

void HouseInformations::deserializeAs_HouseInformations(Reader *param1)
{
  uint _loc5_ = 0;
  uint _loc2_ = param1->readByte();
  this->isOnSale = BooleanByteWrapper::getFlag(_loc2_, 0);
  this->isSaleLocked = BooleanByteWrapper::getFlag(_loc2_, 1);
  this->houseId = param1->readVarUhInt();
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseInformations -"<<"Forbidden value (" << this->houseId << ") on element of HouseInformations.houseId.";
  }
  else
  {
    uint _loc3_ = param1->readUShort();
    uint _loc4_ = 0;
    while(_loc4_ < _loc3_)
    {
      _loc5_ = param1->readInt();
      if(_loc5_ < 0)
      {
        qDebug()<<"ERREUR - HouseInformations -"<<"Forbidden value (" << _loc5_ << ") on elements of doorsOnMap.";
      }
      else
      {
        this->doorsOnMap.append(_loc5_);
        _loc4_++;
        continue;
      }
    }
    this->ownerName = param1->readUTF();
    this->modelId = param1->readVarUhShort();
    if(this->modelId < 0)
    {
      qDebug()<<"ERREUR - HouseInformations -"<<"Forbidden value (" << this->modelId << ") on element of HouseInformations.modelId.";
    }
    else
    {
      return;
    }
  }
}

HouseInformations::HouseInformations()
{
  m_types<<ClassEnum::HOUSEINFORMATIONS;
}

bool HouseInformations::operator==(const HouseInformations &compared)
{
  if(houseId == compared.houseId)
  if(doorsOnMap == compared.doorsOnMap)
  if(ownerName == compared.ownerName)
  if(isOnSale == compared.isOnSale)
  if(isSaleLocked == compared.isSaleLocked)
  if(modelId == compared.modelId)
  return true;
  
  return false;
}

