#include "FriendSpouseOnlineInformations.h"

void FriendSpouseOnlineInformations::serialize(Writer *param1)
{
  this->serializeAs_FriendSpouseOnlineInformations(param1);
}

void FriendSpouseOnlineInformations::serializeAs_FriendSpouseOnlineInformations(Writer *param1)
{
  FriendSpouseInformations::serializeAs_FriendSpouseInformations(param1);
  uint _loc2_ = 0;
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->inFight);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->followSpouse);
  param1->writeByte(_loc2_);
  if(this->mapId < 0)
  {
    qDebug()<<"ERREUR - FriendSpouseOnlineInformations -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  else
  {
    param1->writeInt((int)this->mapId);
    if(this->subAreaId < 0)
    {
      qDebug()<<"ERREUR - FriendSpouseOnlineInformations -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
    }
    else
    {
      param1->writeVarShort((int)this->subAreaId);
      return;
    }
  }
}

void FriendSpouseOnlineInformations::deserialize(Reader *param1)
{
  this->deserializeAs_FriendSpouseOnlineInformations(param1);
}

void FriendSpouseOnlineInformations::deserializeAs_FriendSpouseOnlineInformations(Reader *param1)
{
  FriendSpouseInformations::deserialize(param1);
  uint _loc2_ = param1->readByte();
  this->inFight = BooleanByteWrapper::getFlag(_loc2_, 0);
  this->followSpouse = BooleanByteWrapper::getFlag(_loc2_, 1);
  this->mapId = param1->readInt();
  if(this->mapId < 0)
  {
    qDebug()<<"ERREUR - FriendSpouseOnlineInformations -"<<"Forbidden value (" << this->mapId << ") on element of FriendSpouseOnlineInformations.mapId.";
  }
  else
  {
    this->subAreaId = param1->readVarUhShort();
    if(this->subAreaId < 0)
    {
      qDebug()<<"ERREUR - FriendSpouseOnlineInformations -"<<"Forbidden value (" << this->subAreaId << ") on element of FriendSpouseOnlineInformations.subAreaId.";
    }
    else
    {
      return;
    }
  }
}

FriendSpouseOnlineInformations::FriendSpouseOnlineInformations()
{
  m_types<<ClassEnum::FRIENDSPOUSEONLINEINFORMATIONS;
}

bool FriendSpouseOnlineInformations::operator==(const FriendSpouseOnlineInformations &compared)
{
  if(mapId == compared.mapId)
  if(subAreaId == compared.subAreaId)
  if(inFight == compared.inFight)
  if(followSpouse == compared.followSpouse)
  return true;
  
  return false;
}

