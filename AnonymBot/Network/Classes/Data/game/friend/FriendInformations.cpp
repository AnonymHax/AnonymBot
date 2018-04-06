#include "FriendInformations.h"

void FriendInformations::serialize(Writer *param1)
{
  this->serializeAs_FriendInformations(param1);
}

void FriendInformations::serializeAs_FriendInformations(Writer *param1)
{
  AbstractContactInformations::serializeAs_AbstractContactInformations(param1);
  param1->writeByte(this->playerState);
  if(this->lastConnection < 0)
  {
    qDebug()<<"ERREUR - FriendInformations -"<<"Forbidden value (" << this->lastConnection << ") on element lastConnection.";
  }
  else
  {
    param1->writeVarShort((int)this->lastConnection);
    param1->writeInt((int)this->achievementPoints);
    return;
  }
}

void FriendInformations::deserialize(Reader *param1)
{
  this->deserializeAs_FriendInformations(param1);
}

void FriendInformations::deserializeAs_FriendInformations(Reader *param1)
{
  AbstractContactInformations::deserialize(param1);
  this->playerState = param1->readByte();
  if(this->playerState < 0)
  {
    qDebug()<<"ERREUR - FriendInformations -"<<"Forbidden value (" << this->playerState << ") on element of FriendInformations.playerState.";
  }
  else
  {
    this->lastConnection = param1->readVarUhShort();
    if(this->lastConnection < 0)
    {
      qDebug()<<"ERREUR - FriendInformations -"<<"Forbidden value (" << this->lastConnection << ") on element of FriendInformations.lastConnection.";
    }
    else
    {
      this->achievementPoints = param1->readInt();
      return;
    }
  }
}

FriendInformations::FriendInformations()
{
  m_types<<ClassEnum::FRIENDINFORMATIONS;
}

bool FriendInformations::operator==(const FriendInformations &compared)
{
  if(playerState == compared.playerState)
  if(lastConnection == compared.lastConnection)
  if(achievementPoints == compared.achievementPoints)
  return true;
  
  return false;
}

