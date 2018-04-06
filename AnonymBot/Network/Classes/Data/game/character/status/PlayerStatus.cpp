#include "PlayerStatus.h"

void PlayerStatus::serialize(Writer *param1)
{
  this->serializeAs_PlayerStatus(param1);
}

void PlayerStatus::serializeAs_PlayerStatus(Writer *param1)
{
  param1->writeByte(this->statusId);
}

void PlayerStatus::deserialize(Reader *param1)
{
  this->deserializeAs_PlayerStatus(param1);
}

void PlayerStatus::deserializeAs_PlayerStatus(Reader *param1)
{
  this->statusId = param1->readByte();
  if(this->statusId < 0)
  {
    qDebug()<<"ERREUR - PlayerStatus -"<<"Forbidden value (" << this->statusId << ") on element of PlayerStatus.statusId.";
  }
  else
  {
    return;
  }
}

PlayerStatus::PlayerStatus()
{
  m_types<<ClassEnum::PLAYERSTATUS;
}

bool PlayerStatus::operator==(const PlayerStatus &compared)
{
  if(statusId == compared.statusId)
  return true;
  
  return false;
}

