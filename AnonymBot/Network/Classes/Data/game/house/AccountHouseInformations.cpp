#include "AccountHouseInformations.h"

void AccountHouseInformations::serialize(Writer *param1)
{
  this->serializeAs_AccountHouseInformations(param1);
}

void AccountHouseInformations::serializeAs_AccountHouseInformations(Writer *param1)
{
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - AccountHouseInformations -"<<"Forbidden value (" << this->houseId << ") on element houseId.";
  }
  else
  {
    param1->writeVarInt((int)this->houseId);
    if(this->modelId < 0)
    {
      qDebug()<<"ERREUR - AccountHouseInformations -"<<"Forbidden value (" << this->modelId << ") on element modelId.";
    }
    else
    {
      param1->writeVarShort((int)this->modelId);
      if(this->worldX < -255 || this->worldX > 255)
      {
        qDebug()<<"ERREUR - AccountHouseInformations -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
      }
      else
      {
        param1->writeShort((short)this->worldX);
        if(this->worldY < -255 || this->worldY > 255)
        {
          qDebug()<<"ERREUR - AccountHouseInformations -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
        }
        else
        {
          param1->writeShort((short)this->worldY);
          param1->writeInt((int)this->mapId);
          if(this->subAreaId < 0)
          {
            qDebug()<<"ERREUR - AccountHouseInformations -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
          }
          else
          {
            param1->writeVarShort((int)this->subAreaId);
            return;
          }
        }
      }
    }
  }
}

void AccountHouseInformations::deserialize(Reader *param1)
{
  this->deserializeAs_AccountHouseInformations(param1);
}

void AccountHouseInformations::deserializeAs_AccountHouseInformations(Reader *param1)
{
  this->houseId = param1->readVarUhInt();
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - AccountHouseInformations -"<<"Forbidden value (" << this->houseId << ") on element of AccountHouseInformations.houseId.";
  }
  else
  {
    this->modelId = param1->readVarUhShort();
    if(this->modelId < 0)
    {
      qDebug()<<"ERREUR - AccountHouseInformations -"<<"Forbidden value (" << this->modelId << ") on element of AccountHouseInformations.modelId.";
    }
    else
    {
      this->worldX = param1->readShort();
      if(this->worldX < -255 || this->worldX > 255)
      {
        qDebug()<<"ERREUR - AccountHouseInformations -"<<"Forbidden value (" << this->worldX << ") on element of AccountHouseInformations.worldX.";
      }
      else
      {
        this->worldY = param1->readShort();
        if(this->worldY < -255 || this->worldY > 255)
        {
          qDebug()<<"ERREUR - AccountHouseInformations -"<<"Forbidden value (" << this->worldY << ") on element of AccountHouseInformations.worldY.";
        }
        else
        {
          this->mapId = param1->readInt();
          this->subAreaId = param1->readVarUhShort();
          if(this->subAreaId < 0)
          {
            qDebug()<<"ERREUR - AccountHouseInformations -"<<"Forbidden value (" << this->subAreaId << ") on element of AccountHouseInformations.subAreaId.";
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

AccountHouseInformations::AccountHouseInformations()
{
  m_types<<ClassEnum::ACCOUNTHOUSEINFORMATIONS;
}

bool AccountHouseInformations::operator==(const AccountHouseInformations &compared)
{
  if(houseId == compared.houseId)
  if(modelId == compared.modelId)
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(mapId == compared.mapId)
  if(subAreaId == compared.subAreaId)
  return true;
  
  return false;
}

