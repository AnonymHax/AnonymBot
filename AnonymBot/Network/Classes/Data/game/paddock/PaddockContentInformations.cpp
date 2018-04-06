#include "PaddockContentInformations.h"

void PaddockContentInformations::serialize(Writer *param1)
{
  this->serializeAs_PaddockContentInformations(param1);
}

void PaddockContentInformations::serializeAs_PaddockContentInformations(Writer *param1)
{
  PaddockInformations::serializeAs_PaddockInformations(param1);
  param1->writeInt((int)this->paddockId);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - PaddockContentInformations -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  else
  {
    param1->writeShort((short)this->worldX);
    if(this->worldY < -255 || this->worldY > 255)
    {
      qDebug()<<"ERREUR - PaddockContentInformations -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
    }
    else
    {
      param1->writeShort((short)this->worldY);
      param1->writeInt((int)this->mapId);
      if(this->subAreaId < 0)
      {
        qDebug()<<"ERREUR - PaddockContentInformations -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
      }
      else
      {
        param1->writeVarShort((int)this->subAreaId);
        param1->writeBool(this->abandonned);
        param1->writeShort((short)this->mountsInformations.size());
        uint _loc2_ = 0;
        while(_loc2_ < this->mountsInformations.size())
        {
          (this->mountsInformations[_loc2_]).serializeAs_MountInformationsForPaddock(param1);
          _loc2_++;
        }
        return;
      }
    }
  }
}

void PaddockContentInformations::deserialize(Reader *param1)
{
  this->deserializeAs_PaddockContentInformations(param1);
}

void PaddockContentInformations::deserializeAs_PaddockContentInformations(Reader *param1)
{
  MountInformationsForPaddock _loc4_ ;
  PaddockInformations::deserialize(param1);
  this->paddockId = param1->readInt();
  this->worldX = param1->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - PaddockContentInformations -"<<"Forbidden value (" << this->worldX << ") on element of PaddockContentInformations.worldX.";
  }
  else
  {
    this->worldY = param1->readShort();
    if(this->worldY < -255 || this->worldY > 255)
    {
      qDebug()<<"ERREUR - PaddockContentInformations -"<<"Forbidden value (" << this->worldY << ") on element of PaddockContentInformations.worldY.";
    }
    else
    {
      this->mapId = param1->readInt();
      this->subAreaId = param1->readVarUhShort();
      if(this->subAreaId < 0)
      {
        qDebug()<<"ERREUR - PaddockContentInformations -"<<"Forbidden value (" << this->subAreaId << ") on element of PaddockContentInformations.subAreaId.";
      }
      else
      {
        this->abandonned = param1->readBool();
        uint _loc2_ = param1->readUShort();
        uint _loc3_ = 0;
        while(_loc3_ < _loc2_)
        {
          _loc4_ = MountInformationsForPaddock();
          _loc4_.deserialize(param1);
          this->mountsInformations.append(_loc4_);
          _loc3_++;
        }
        return;
      }
    }
  }
}

PaddockContentInformations::PaddockContentInformations()
{
  m_types<<ClassEnum::PADDOCKCONTENTINFORMATIONS;
}

bool PaddockContentInformations::operator==(const PaddockContentInformations &compared)
{
  if(paddockId == compared.paddockId)
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(mapId == compared.mapId)
  if(subAreaId == compared.subAreaId)
  if(abandonned == compared.abandonned)
  if(mountsInformations == compared.mountsInformations)
  return true;
  
  return false;
}

