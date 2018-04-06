#include "HouseInformationsForGuild.h"

void HouseInformationsForGuild::serialize(Writer *param1)
{
  this->serializeAs_HouseInformationsForGuild(param1);
}

void HouseInformationsForGuild::serializeAs_HouseInformationsForGuild(Writer *param1)
{
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseInformationsForGuild -"<<"Forbidden value (" << this->houseId << ") on element houseId.";
  }
  else
  {
    param1->writeVarInt((int)this->houseId);
    if(this->modelId < 0)
    {
      qDebug()<<"ERREUR - HouseInformationsForGuild -"<<"Forbidden value (" << this->modelId << ") on element modelId.";
    }
    else
    {
      param1->writeVarInt((int)this->modelId);
      param1->writeUTF(this->ownerName);
      if(this->worldX < -255 || this->worldX > 255)
      {
        qDebug()<<"ERREUR - HouseInformationsForGuild -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
      }
      else
      {
        param1->writeShort((short)this->worldX);
        if(this->worldY < -255 || this->worldY > 255)
        {
          qDebug()<<"ERREUR - HouseInformationsForGuild -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
        }
        else
        {
          param1->writeShort((short)this->worldY);
          param1->writeInt((int)this->mapId);
          if(this->subAreaId < 0)
          {
            qDebug()<<"ERREUR - HouseInformationsForGuild -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
          }
          else
          {
            param1->writeVarShort((int)this->subAreaId);
            param1->writeShort((short)this->skillListIds.size());
            uint _loc2_ = 0;
            while(_loc2_ < this->skillListIds.size())
            {
              param1->writeInt((int)this->skillListIds[_loc2_]);
              _loc2_++;
            }
            if(this->guildshareParams < 0)
            {
              qDebug()<<"ERREUR - HouseInformationsForGuild -"<<"Forbidden value (" << this->guildshareParams << ") on element guildshareParams.";
            }
            else
            {
              param1->writeVarInt((int)this->guildshareParams);
              return;
            }
          }
        }
      }
    }
  }
}

void HouseInformationsForGuild::deserialize(Reader *param1)
{
  this->deserializeAs_HouseInformationsForGuild(param1);
}

void HouseInformationsForGuild::deserializeAs_HouseInformationsForGuild(Reader *param1)
{
  auto _loc4_ = 0;
  this->houseId = param1->readVarUhInt();
  if(this->houseId < 0)
  {
    qDebug()<<"ERREUR - HouseInformationsForGuild -"<<"Forbidden value (" << this->houseId << ") on element of HouseInformationsForGuild.houseId.";
  }
  else
  {
    this->modelId = param1->readVarUhInt();
    if(this->modelId < 0)
    {
      qDebug()<<"ERREUR - HouseInformationsForGuild -"<<"Forbidden value (" << this->modelId << ") on element of HouseInformationsForGuild.modelId.";
    }
    else
    {
      this->ownerName = param1->readUTF();
      this->worldX = param1->readShort();
      if(this->worldX < -255 || this->worldX > 255)
      {
        qDebug()<<"ERREUR - HouseInformationsForGuild -"<<"Forbidden value (" << this->worldX << ") on element of HouseInformationsForGuild.worldX.";
      }
      else
      {
        this->worldY = param1->readShort();
        if(this->worldY < -255 || this->worldY > 255)
        {
          qDebug()<<"ERREUR - HouseInformationsForGuild -"<<"Forbidden value (" << this->worldY << ") on element of HouseInformationsForGuild.worldY.";
        }
        else
        {
          this->mapId = param1->readInt();
          this->subAreaId = param1->readVarUhShort();
          if(this->subAreaId < 0)
          {
            qDebug()<<"ERREUR - HouseInformationsForGuild -"<<"Forbidden value (" << this->subAreaId << ") on element of HouseInformationsForGuild.subAreaId.";
          }
          else
          {
            uint _loc2_ = param1->readUShort();
            uint _loc3_ = 0;
            while(_loc3_ < _loc2_)
            {
              _loc4_ = param1->readInt();
              this->skillListIds.append(_loc4_);
              _loc3_++;
            }
            this->guildshareParams = param1->readVarUhInt();
            if(this->guildshareParams < 0)
            {
              qDebug()<<"ERREUR - HouseInformationsForGuild -"<<"Forbidden value (" << this->guildshareParams << ") on element of HouseInformationsForGuild.guildshareParams.";
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
}

HouseInformationsForGuild::HouseInformationsForGuild()
{
  m_types<<ClassEnum::HOUSEINFORMATIONSFORGUILD;
}

bool HouseInformationsForGuild::operator==(const HouseInformationsForGuild &compared)
{
  if(houseId == compared.houseId)
  if(modelId == compared.modelId)
  if(ownerName == compared.ownerName)
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(mapId == compared.mapId)
  if(subAreaId == compared.subAreaId)
  if(skillListIds == compared.skillListIds)
  if(guildshareParams == compared.guildshareParams)
  return true;
  
  return false;
}

