#include "PartyMemberGeoPosition.h"

void PartyMemberGeoPosition::serialize(Writer *param1)
{
  this->serializeAs_PartyMemberGeoPosition(param1);
}

void PartyMemberGeoPosition::serializeAs_PartyMemberGeoPosition(Writer *param1)
{
  if(this->memberId < 0)
  {
    qDebug()<<"ERREUR - PartyMemberGeoPosition -"<<"Forbidden value (" << this->memberId << ") on element memberId.";
  }
  else
  {
    param1->writeInt((int)this->memberId);
    if(this->worldX < -255 || this->worldX > 255)
    {
      qDebug()<<"ERREUR - PartyMemberGeoPosition -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
    }
    else
    {
      param1->writeShort((short)this->worldX);
      if(this->worldY < -255 || this->worldY > 255)
      {
        qDebug()<<"ERREUR - PartyMemberGeoPosition -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
      }
      else
      {
        param1->writeShort((short)this->worldY);
        param1->writeInt((int)this->mapId);
        if(this->subAreaId < 0)
        {
          qDebug()<<"ERREUR - PartyMemberGeoPosition -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
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

void PartyMemberGeoPosition::deserialize(Reader *param1)
{
  this->deserializeAs_PartyMemberGeoPosition(param1);
}

void PartyMemberGeoPosition::deserializeAs_PartyMemberGeoPosition(Reader *param1)
{
  this->memberId = param1->readInt();
  if(this->memberId < 0)
  {
    qDebug()<<"ERREUR - PartyMemberGeoPosition -"<<"Forbidden value (" << this->memberId << ") on element of PartyMemberGeoPosition.memberId.";
  }
  else
  {
    this->worldX = param1->readShort();
    if(this->worldX < -255 || this->worldX > 255)
    {
      qDebug()<<"ERREUR - PartyMemberGeoPosition -"<<"Forbidden value (" << this->worldX << ") on element of PartyMemberGeoPosition.worldX.";
    }
    else
    {
      this->worldY = param1->readShort();
      if(this->worldY < -255 || this->worldY > 255)
      {
        qDebug()<<"ERREUR - PartyMemberGeoPosition -"<<"Forbidden value (" << this->worldY << ") on element of PartyMemberGeoPosition.worldY.";
      }
      else
      {
        this->mapId = param1->readInt();
        this->subAreaId = param1->readVarUhShort();
        if(this->subAreaId < 0)
        {
          qDebug()<<"ERREUR - PartyMemberGeoPosition -"<<"Forbidden value (" << this->subAreaId << ") on element of PartyMemberGeoPosition.subAreaId.";
        }
        else
        {
          return;
        }
      }
    }
  }
}

PartyMemberGeoPosition::PartyMemberGeoPosition()
{
  m_types<<ClassEnum::PARTYMEMBERGEOPOSITION;
}

bool PartyMemberGeoPosition::operator==(const PartyMemberGeoPosition &compared)
{
  if(memberId == compared.memberId)
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(mapId == compared.mapId)
  if(subAreaId == compared.subAreaId)
  return true;
  
  return false;
}

