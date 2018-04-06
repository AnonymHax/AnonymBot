#include "HouseInformationsForSell.h"

void HouseInformationsForSell::serialize(Writer *param1)
{
  this->serializeAs_HouseInformationsForSell(param1);
}

void HouseInformationsForSell::serializeAs_HouseInformationsForSell(Writer *param1)
{
  if(this->modelId < 0)
  {
    qDebug()<<"ERREUR - HouseInformationsForSell -"<<"Forbidden value (" << this->modelId << ") on element modelId.";
  }
  else
  {
    param1->writeVarInt((int)this->modelId);
    param1->writeUTF(this->ownerName);
    param1->writeBool(this->ownerConnected);
    if(this->worldX < -255 || this->worldX > 255)
    {
      qDebug()<<"ERREUR - HouseInformationsForSell -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
    }
    else
    {
      param1->writeShort((short)this->worldX);
      if(this->worldY < -255 || this->worldY > 255)
      {
        qDebug()<<"ERREUR - HouseInformationsForSell -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
      }
      else
      {
        param1->writeShort((short)this->worldY);
        if(this->subAreaId < 0)
        {
          qDebug()<<"ERREUR - HouseInformationsForSell -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
        }
        else
        {
          param1->writeVarShort((int)this->subAreaId);
          param1->writeByte(this->nbRoom);
          param1->writeByte(this->nbChest);
          param1->writeShort((short)this->skillListIds.size());
          uint _loc2_ = 0;
          while(_loc2_ < this->skillListIds.size())
          {
            param1->writeInt((int)this->skillListIds[_loc2_]);
            _loc2_++;
          }
          param1->writeBool(this->isLocked);
          if(this->price < 0)
          {
            qDebug()<<"ERREUR - HouseInformationsForSell -"<<"Forbidden value (" << this->price << ") on element price.";
          }
          else
          {
            param1->writeVarInt((int)this->price);
            return;
          }
        }
      }
    }
  }
}

void HouseInformationsForSell::deserialize(Reader *param1)
{
  this->deserializeAs_HouseInformationsForSell(param1);
}

void HouseInformationsForSell::deserializeAs_HouseInformationsForSell(Reader *param1)
{
  auto _loc4_ = 0;
  this->modelId = param1->readVarUhInt();
  if(this->modelId < 0)
  {
    qDebug()<<"ERREUR - HouseInformationsForSell -"<<"Forbidden value (" << this->modelId << ") on element of HouseInformationsForSell.modelId.";
  }
  else
  {
    this->ownerName = param1->readUTF();
    this->ownerConnected = param1->readBool();
    this->worldX = param1->readShort();
    if(this->worldX < -255 || this->worldX > 255)
    {
      qDebug()<<"ERREUR - HouseInformationsForSell -"<<"Forbidden value (" << this->worldX << ") on element of HouseInformationsForSell.worldX.";
    }
    else
    {
      this->worldY = param1->readShort();
      if(this->worldY < -255 || this->worldY > 255)
      {
        qDebug()<<"ERREUR - HouseInformationsForSell -"<<"Forbidden value (" << this->worldY << ") on element of HouseInformationsForSell.worldY.";
      }
      else
      {
        this->subAreaId = param1->readVarUhShort();
        if(this->subAreaId < 0)
        {
          qDebug()<<"ERREUR - HouseInformationsForSell -"<<"Forbidden value (" << this->subAreaId << ") on element of HouseInformationsForSell.subAreaId.";
        }
        else
        {
          this->nbRoom = param1->readByte();
          this->nbChest = param1->readByte();
          uint _loc2_ = param1->readUShort();
          uint _loc3_ = 0;
          while(_loc3_ < _loc2_)
          {
            _loc4_ = param1->readInt();
            this->skillListIds.append(_loc4_);
            _loc3_++;
          }
          this->isLocked = param1->readBool();
          this->price = param1->readVarUhInt();
          if(this->price < 0)
          {
            qDebug()<<"ERREUR - HouseInformationsForSell -"<<"Forbidden value (" << this->price << ") on element of HouseInformationsForSell.price.";
          }
          else
          {
            return;
          }
        }
      }
    }
  }
}

HouseInformationsForSell::HouseInformationsForSell()
{
  m_types<<ClassEnum::HOUSEINFORMATIONSFORSELL;
}

bool HouseInformationsForSell::operator==(const HouseInformationsForSell &compared)
{
  if(modelId == compared.modelId)
  if(ownerName == compared.ownerName)
  if(ownerConnected == compared.ownerConnected)
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(subAreaId == compared.subAreaId)
  if(nbRoom == compared.nbRoom)
  if(nbChest == compared.nbChest)
  if(skillListIds == compared.skillListIds)
  if(isLocked == compared.isLocked)
  if(price == compared.price)
  return true;
  
  return false;
}

