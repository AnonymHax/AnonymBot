#include "HouseInformationsInside.h"

void HouseInformationsInside::serialize(Writer *param1)
{
  this->serializeAs_HouseInformationsInside(param1);
}

void HouseInformationsInside::serializeAs_HouseInformationsInside(Writer *param1)
{
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseInformationsInside -"<<"Forbidden value (" << this->houseId << ") on element houseId.";
  }
  else
  {
    param1->writeVarInt((int)this->houseId);
    if(this->modelId < 0)
    {
      qDebug()<<"ERREUR - HouseInformationsInside -"<<"Forbidden value (" << this->modelId << ") on element modelId.";
    }
    else
    {
      param1->writeVarShort((int)this->modelId);
      param1->writeInt((int)this->ownerId);
      param1->writeUTF(this->ownerName);
      if(this->worldX < -255 || this->worldX > 255)
      {
        qDebug()<<"ERREUR - HouseInformationsInside -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
      }
      else
      {
        param1->writeShort((short)this->worldX);
        if(this->worldY < -255 || this->worldY > 255)
        {
          qDebug()<<"ERREUR - HouseInformationsInside -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
        }
        else
        {
          param1->writeShort((short)this->worldY);
          if(this->price < 0)
          {
            qDebug()<<"ERREUR - HouseInformationsInside -"<<"Forbidden value (" << this->price << ") on element price.";
          }
          else
          {
            param1->writeInt((int)this->price);
            param1->writeBool(this->isLocked);
            return;
          }
        }
      }
    }
  }
}

void HouseInformationsInside::deserialize(Reader *param1)
{
  this->deserializeAs_HouseInformationsInside(param1);
}

void HouseInformationsInside::deserializeAs_HouseInformationsInside(Reader *param1)
{
  this->houseId = param1->readVarUhInt();
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseInformationsInside -"<<"Forbidden value (" << this->houseId << ") on element of HouseInformationsInside.houseId.";
  }
  else
  {
    this->modelId = param1->readVarUhShort();
    if(this->modelId < 0)
    {
      qDebug()<<"ERREUR - HouseInformationsInside -"<<"Forbidden value (" << this->modelId << ") on element of HouseInformationsInside.modelId.";
    }
    else
    {
      this->ownerId = param1->readInt();
      this->ownerName = param1->readUTF();
      this->worldX = param1->readShort();
      if(this->worldX < -255 || this->worldX > 255)
      {
        qDebug()<<"ERREUR - HouseInformationsInside -"<<"Forbidden value (" << this->worldX << ") on element of HouseInformationsInside.worldX.";
      }
      else
      {
        this->worldY = param1->readShort();
        if(this->worldY < -255 || this->worldY > 255)
        {
          qDebug()<<"ERREUR - HouseInformationsInside -"<<"Forbidden value (" << this->worldY << ") on element of HouseInformationsInside.worldY.";
        }
        else
        {
          this->price = param1->readInt();
          if(this->price < 0)
          {
            qDebug()<<"ERREUR - HouseInformationsInside -"<<"Forbidden value (" << this->price << ") on element of HouseInformationsInside.price.";
          }
          else
          {
            this->isLocked = param1->readBool();
            return;
          }
        }
      }
    }
  }
}

HouseInformationsInside::HouseInformationsInside()
{
  m_types<<ClassEnum::HOUSEINFORMATIONSINSIDE;
}

bool HouseInformationsInside::operator==(const HouseInformationsInside &compared)
{
  if(houseId == compared.houseId)
  if(modelId == compared.modelId)
  if(ownerId == compared.ownerId)
  if(ownerName == compared.ownerName)
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(price == compared.price)
  if(isLocked == compared.isLocked)
  return true;
  
  return false;
}

