#include "JobCrafterDirectoryEntryPlayerInfo.h"

void JobCrafterDirectoryEntryPlayerInfo::serialize(Writer *param1)
{
  this->serializeAs_JobCrafterDirectoryEntryPlayerInfo(param1);
}

void JobCrafterDirectoryEntryPlayerInfo::serializeAs_JobCrafterDirectoryEntryPlayerInfo(Writer *param1)
{
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryEntryPlayerInfo -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  else
  {
    param1->writeVarLong((double)this->playerId);
    param1->writeUTF(this->playerName);
    param1->writeByte(this->alignmentSide);
    param1->writeByte(this->breed);
    param1->writeBool(this->sex);
    param1->writeBool(this->isInWorkshop);
    if(this->worldX < -255 || this->worldX > 255)
    {
      qDebug()<<"ERREUR - JobCrafterDirectoryEntryPlayerInfo -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
    }
    else
    {
      param1->writeShort((short)this->worldX);
      if(this->worldY < -255 || this->worldY > 255)
      {
        qDebug()<<"ERREUR - JobCrafterDirectoryEntryPlayerInfo -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
      }
      else
      {
        param1->writeShort((short)this->worldY);
        param1->writeInt((int)this->mapId);
        if(this->subAreaId < 0)
        {
          qDebug()<<"ERREUR - JobCrafterDirectoryEntryPlayerInfo -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
        }
        else
        {
          param1->writeVarShort((int)this->subAreaId);
          param1->writeShort((short)this->status->getTypes().last());
          this->status->serialize(param1);
          return;
        }
      }
    }
  }
}

void JobCrafterDirectoryEntryPlayerInfo::deserialize(Reader *param1)
{
  this->deserializeAs_JobCrafterDirectoryEntryPlayerInfo(param1);
}

void JobCrafterDirectoryEntryPlayerInfo::deserializeAs_JobCrafterDirectoryEntryPlayerInfo(Reader *param1)
{
  this->playerId = param1->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - JobCrafterDirectoryEntryPlayerInfo -"<<"Forbidden value (" << this->playerId << ") on element of JobCrafterDirectoryEntryPlayerInfo.playerId.";
  }
  else
  {
    this->playerName = param1->readUTF();
    this->alignmentSide = param1->readByte();
    this->breed = param1->readByte();
    if(this->breed < (int)PlayableBreedEnum::FECA || this->breed > (int)PlayableBreedEnum::HUPPERMAGE)
    {
      qDebug()<<"ERREUR - JobCrafterDirectoryEntryPlayerInfo -"<<"Forbidden value (" << this->breed << ") on element of JobCrafterDirectoryEntryPlayerInfo.breed.";
    }
    else
    {
      this->sex = param1->readBool();
      this->isInWorkshop = param1->readBool();
      this->worldX = param1->readShort();
      if(this->worldX < -255 || this->worldX > 255)
      {
        qDebug()<<"ERREUR - JobCrafterDirectoryEntryPlayerInfo -"<<"Forbidden value (" << this->worldX << ") on element of JobCrafterDirectoryEntryPlayerInfo.worldX.";
      }
      else
      {
        this->worldY = param1->readShort();
        if(this->worldY < -255 || this->worldY > 255)
        {
          qDebug()<<"ERREUR - JobCrafterDirectoryEntryPlayerInfo -"<<"Forbidden value (" << this->worldY << ") on element of JobCrafterDirectoryEntryPlayerInfo.worldY.";
        }
        else
        {
          this->mapId = param1->readInt();
          this->subAreaId = param1->readVarUhShort();
          if(this->subAreaId < 0)
          {
            qDebug()<<"ERREUR - JobCrafterDirectoryEntryPlayerInfo -"<<"Forbidden value (" << this->subAreaId << ") on element of JobCrafterDirectoryEntryPlayerInfo.subAreaId.";
          }
          else
          {
            uint _loc2_ = param1->readUShort();
            this->status = qSharedPointerCast<PlayerStatus>(ClassManagerSingleton::get()->getClass(_loc2_));
            this->status->deserialize(param1);
            return;
          }
        }
      }
    }
  }
}

JobCrafterDirectoryEntryPlayerInfo::JobCrafterDirectoryEntryPlayerInfo()
{
  m_types<<ClassEnum::JOBCRAFTERDIRECTORYENTRYPLAYERINFO;
}

bool JobCrafterDirectoryEntryPlayerInfo::operator==(const JobCrafterDirectoryEntryPlayerInfo &compared)
{
  if(playerId == compared.playerId)
  if(playerName == compared.playerName)
  if(alignmentSide == compared.alignmentSide)
  if(breed == compared.breed)
  if(sex == compared.sex)
  if(isInWorkshop == compared.isInWorkshop)
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(mapId == compared.mapId)
  if(subAreaId == compared.subAreaId)
  if(status == compared.status)
  return true;
  
  return false;
}

